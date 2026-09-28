//
// Created by maks on 06.01.2025.
//

#include "jvm_hooks.h"

#include <android/api-level.h>

#include "environ/environ.h"
#include "../ctxbridges/loader_dlopen.h"

#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>

#define TAG __FILE_NAME__
#include <log.h>

extern void* maybe_load_vulkan();

/**
 * Basically a verbatim implementation of ndlopen(), found at
 * https://github.com/PojavLauncherTeam/lwjgl3/blob/3.3.1/modules/lwjgl/core/src/generated/c/linux/org_lwjgl_system_linux_DynamicLinkLoader.c#L11
 * but with our own additions for stuff like vulkanmod.
 */
static jlong ndlopen_bugfix(__attribute__((unused)) JNIEnv *env,
                     __attribute__((unused)) jclass class,
                     jlong filename_ptr,
                     jint jmode) {
    const char* filename = (const char*) filename_ptr;

    // Oveeride vulkan loading to let us load vulkan ourselves
    if(strstr(filename, "libvulkan.so") == filename) {
        printf("LWJGL linkerhook: replacing load for libvulkan.so with custom driver\n");
        return (jlong) maybe_load_vulkan();
    }

    // Minecraft 26.3+ (renderpearl GlBackend) loads EGL through LWJGL itself instead of going
    // through GLFW, so it asks the linker for the desktop-Linux name (libEGL.so / libEGL.so.1),
    // which either doesn't exist on Android or would bypass the selected renderer entirely
    // (the "Could not load EGL library" failure). Hand it the renderer's EGL library instead,
    // the same one egl_loader.c uses (LTW, MobileGlues, ...). Names like libEGL_angle.so are
    // left alone since they don't match the prefix below.
    if(strncmp(filename, "libEGL.so", 9) == 0) {
        const char* rendererEgl = getenv("POJAVEXEC_EGL");
        printf("LWJGL linkerhook: EGL requested as '%s', renderer EGL is '%s'\n",
               filename, rendererEgl ? rendererEgl : "(unset)");
        if(rendererEgl != NULL) {
            void* handle = loader_dlopen((char*) rendererEgl, "libEGL.so", (int)jmode);
            if(handle != NULL) return (jlong) handle;
            printf("LWJGL linkerhook: failed to load renderer EGL, falling back to default lookup\n");
        }
    }

    // This hook also serves the task of mitigating a bug: the idea is that since, on Android 10 and
    // earlier, the linker doesn't really do namespace nesting.
    // It is not a problem as most of the libraries are in the launcher path, but when you try to run
    // VulkanMod which loads shaderc outside of the default jni libs directory through this method,
    // it can't load it because the path is not in the allowed paths for the anonymous namesapce.
    // This method fixes the issue by being in libpojavexec, and thus being in the classloader namespace

    int mode = (int)jmode;
    return (jlong) dlopen(filename, mode);
}

/**
 * Install the LWJGL dlopen hook. This allows us to mitigate linker bugs and add custom library overrides.
 */
void installLwjglDlopenHook(JNIEnv *env) {
    LOGI("Installing LWJGL dlopen() hook");
    jclass dynamicLinkLoader = (*env)->FindClass(env, "org/lwjgl/system/linux/DynamicLinkLoader");
    if(dynamicLinkLoader == NULL) {
        LOGE("Failed to find the target class");
        (*env)->ExceptionClear(env);
        return;
    }
    JNINativeMethod ndlopenMethod[] = {
            {"ndlopen", "(JI)J", &ndlopen_bugfix}
    };
    if((*env)->RegisterNatives(env, dynamicLinkLoader, ndlopenMethod, 1) != 0) {
        LOGE("Failed to register the hooked method");
        (*env)->ExceptionClear(env);
    }
}