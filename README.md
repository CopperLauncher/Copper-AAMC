<h1 align="center">Copper Launcher</h1>

<img src="https://github.com/CopperLauncher/Copper-Android/blob/v3_openjdk/app_pojavlauncher/src/main/assets/pojavlauncher.png" align="left" width="130" height="130" alt="Copper logo">


> [!IMPORTANT]
> Copper Launcher has been rebased to MojoLauncher, This repo is currently based on Angel Aura Amethyst, Which is archived now. You can get the updated Copper which is based on MojoLauncher [here](https://github.com/CopperLauncher/Copper-Android).

![GitHub commit activity](https://img.shields.io/github/commit-activity/m/CopperLauncher/Copper-Android)
![GitHub Downloads](https://img.shields.io/github/downloads/CopperLauncher/Copper-Android/total)
![Platform](https://img.shields.io/badge/platform-Android-green)
![Min SDK](https://img.shields.io/badge/minSdk-26-blue)
![Android CI](https://github.com/CopperLauncher/Copper-Android/workflows/Android%20CI/badge.svg)
![Crowdin](https://badges.crowdin.net/pojavlauncher/localized.svg)
[![Discord](https://img.shields.io/discord/1355213558631366897?color=5865F2&logo=discord&logoColor=white&label=&style=flat)](https://discord.gg/j8GTQv3YvY)
[![CurseForge](https://img.shields.io/badge/curseforge-maxjubayeryt-orange?logo=curseforge)](https://www.curseforge.com/members/maxjubayeryt/projects)
[![Modrinth](https://img.shields.io/badge/modrinth-maxjubayeryt-green?logo=modrinth)](https://modrinth.com/user/maxjubayeryt)

Copper is a fork of [Amethyst](https://github.com/AngelAuraMC/Amethyst-Android) that allows you to play Minecraft: Java Edition on your Android devices.

## Table of Contents

* [Introduction](#introduction)
* [Getting Copper](#getting-copper)
* [Building](#building)
    * [Quick Build (Recommended)](#quick-build-recommended)
    * [Detailed Build](#detailed-build)
* [Current Status](#current-status)
* [Known Issues](#known-issues)
* [FAQ](#faq)
* [Contributing](#contributing)
* [Support](#support)
* [License](#license)
* [Credits & Dependencies](#credits--dependencies)
* [Roadmap](#roadmap)

## Introduction

* Copper is a Minecraft: Java Edition launcher for Android based on [Boardwalk](https://github.com/zhuowei/Boardwalk), [PojavLauncher](https://github.com/PojavLauncherTeam/PojavLauncher) and [Amethyst Launcher](https://github.com/AngelAuraMC/Amethyst-Android).
* This launcher can launch almost all available Minecraft versions ranging from rd-132211 to 26.3-snapshot-1 (including Combat Test versions)
* Modding via Forge and Fabric are also supported.
* This repository contains source code for Android.

## Getting Copper

You can get Copper via three methods:

1. **Nightly** Download the latest artifact from [Nightly.link](https://nightly.link/CopperLauncher/Copper-Android/workflows/android/v3_openjdk?preview)
2. **Releases:** Download the latest prebuilt app [from Releases](https://github.com/CopperLauncher/Copper-android/releases/)
3. **Build from Source:** Follow the [building instructions](#building) below.

## Building

### Quick Build (Recommended)

The easiest way to build Copper is to use the pre-built JREs provided by our CI.

1. Clone the repository: `git clone --recursive https://github.com/CopperLauncher/Copper-Android.git`
2. Build the launcher: `./gradlew :app_pojavlauncher:assembleDebug` (Use `gradlew.bat` on Windows)

The built APK will be located in `app_pojavlauncher/build/outputs/apk/debug/`.

### Detailed Build

If you need more control over the build process, follow these steps:

1. **Java Runtime Environment (JRE):** Download the `jre8-pojav` artifact from AngelAuraMCs  [CI auto builds](https://github.com/AngelAuraMC/openjdk-build-multiarch/actions).  This package contains pre-built JREs for all supported architectures.  If you need to build the JRE yourself, follow the instructions in the [android-openjdk-build-multiarch](https://github.com/AngelAuraMC/openjdk-build-multiarch) repository.

2. **LWJGL:** The build instructions for the custom LWJGL are available over the [LWJGL repository](https://github.com/AngelAuraMC/lwjgl3).

3. **Language List:** Because languages are auto-added by Crowdin, you need to run the language list generator before building. In the project directory, run:
   * Linux/macOS:
     ```bash
     chmod +x scripts/languagelist_updater.sh
     bash scripts/languagelist_updater.sh
     ```
   * Windows:
     ```batch
     scripts\languagelist_updater.bat
     ```

4. **Build GLFW stub:** `./gradlew :jre_lwjgl3glfw:build`

5. **Build the launcher:** `./gradlew :app_pojavlauncher:assembleDebug` (Replace `gradlew` with `gradlew.bat` on Windows).

## Current Status

* [x] New UI
* [x] Bug Fixes
* [x] Fix GL4ES and KW in older versions
* [x] Add Modpack export
* [x] Add mclo.gs
* [x] Add Res pack downloader
* [x] Add Shader pack downloader
* [x] Add Res pack manager
* [x] Add Shader pack manager
* [x] Fix Krypton wrapper in 1.21.6 and up
* [x] Bump Mobile Glues
* [x] Add More Renderers (By adding FCL custom renderer plugin support)


## Known Issues

See Copper's [issue tracker](https://github.com/CopperLauncher/Copper-Android/issues) for a list of known issues and their current status.

## Support

For support, please join our [Discord server](https://discord.gg/j8GTQv3YvY)

## License

Copper is licensed under [GNU LGPLv3](https://github.com/CopperLauncher/Copper-Android/blob/v3_openjdk/LICENSE).

## Credits & Dependencies

* [Boardwalk](https://github.com/zhuowei/Boardwalk) (JVM Launcher): Unknown License/[Apache License 2.0](https://github.com/zhuowei/Boardwalk/blob/master/LICENSE) or GNU GPLv2.
* [PojavLauncher](https://github.com/PojavLauncherTeam/PojavLauncher): [GLGPL](https://github.com/PojavLauncherTeam/PojavLauncher/blob/v3_openjdk/LICENSE)
* [Amethyst Launcher](https://github.com/AngelAuraMC/Amethyst-Android/): [LGPL-3.0 license](https://github.com/AngelAuraMC/Amethyst-Android/blob/v3_openjdk/LICENSE)
* [MojoLauncher](https://github.com/MojoLauncher/MojoLauncher/): [LGPL-3.0 license](https://github.com/AngelAuraMC/Amethyst-Android/blob/v3_openjdk/LICENSE)
* [FCL-team](https://github.com/FCL-Team/FoldCraftLauncher/): [GPL-3.0 license](https://github.com/FCL-Team/FoldCraftLauncher/blob/main/LICENSE)
* Android Support Libraries: [Apache License 2.0](https://android.googlesource.com/platform/prebuilts/maven_repo/android/+/master/NOTICE.txt).
* [GL4ES](https://github.com/AngelAuraMC/gl4es): [MIT License](https://github.com/ptitSeb/gl4es/blob/master/LICENSE).
* [Krypton Wrapper](https://github.com/BZLZHH/NG-GL4ES): [MIT License](https://github.com/BZLZHH/NG-GL4ES/blob/main/LICENSE).
* [MobileGlues](https://github.com/MobileGL-Dev/MobileGlues): [LGPL-2.1 License](https://github.com/MobileGL-Dev/MobileGlues/blob/dev-es/LICENSE).
* [ANGLE](https://chromium.googlesource.com/angle/angle): [All Rights Reserved](app_pojavlauncher/src/main/assets/licenses/ANGLE_LICENSE).
* [OpenJDK](https://github.com/AngelAuraMC/openjdk-multiarch-jdk8u): [GNU GPLv2 License](https://openjdk.java.net/legal/gplv2+ce.html).
* [LWJGL3](https://github.com/AngelAuraMC/lwjgl3): [BSD-3 License](https://github.com/LWJGL/lwjgl3/blob/master/LICENSE.md).
* [LWJGLX](https://github.com/AngelAuraMC/lwjglx) (LWJGL2 API compatibility layer for LWJGL3): unknown license.
* [Mesa 3D Graphics Library](https://gitlab.freedesktop.org/mesa/mesa): [MIT License](https://docs.mesa3d.org/license.html).
* [bhook](https://github.com/bytedance/bhook) (Used for exit code trapping): [MIT license](https://github.com/bytedance/bhook/blob/main/LICENSE).
* [libepoxy](https://github.com/anholt/libepoxy): [MIT License](https://github.com/anholt/libepoxy/blob/master/COPYING).
* [virglrenderer](https://github.com/AngelAuraMC/virglrenderer): [MIT License](https://gitlab.freedesktop.org/virgl/virglrenderer/-/blob/master/COPYING).
* [OpenAL-Soft](https://github.com/kcat/openal-soft): [GNU GPLv2](app_pojavlauncher/src/main/assets/licenses/OPENAL-SOFT_GPL2)
  * [oboe](https://github.com/google/oboe): [Apache License 2.0](app_pojavlauncher/src/main/assets/licenses/OBOE_APACHE2).
  * [pfffft](https://bitbucket.org/jpommier/pffft/src/master/): [ARR](app_pojavlauncher/src/main/assets/licenses/PFFFT_LICENSE)
* [SDL3](https://github.com/libsdl-org/SDL): [zlib License](https://github.com/libsdl-org/SDL/blob/main/LICENSE.txt)
* [sdl2-compat](https://github.com/libsdl-org/sdl2-compat): [zlib License](https://github.com/libsdl-org/sdl2-compat/blob/main/LICENSE.txt)
* Thanks to [MCHeads](https://mc-heads.net) for providing Minecraft avatars.
* Thanks to [Modrinth](https://api.modrinth.com/), [CurseForge](https://docs.curseforge.com/rest-api/) and [McLo.gs](https://api.mclo.gs) for providing us the free API's.

## Special thanks
* Thanks to [MojoLauncher](https://github.com/MojoLauncher/MojoLauncher/) for the android icons, Made by [Yarpopcat08](https://github.com/Yarpopcat08).
* Thanks to [FCL-team](https://github.com/FCL-Team/FoldCraftLauncher/) for the custom renderer plugin support that I took some codes from.
* Thanks to [whynelo](https://github.com/whynelo) for the new copper icons.

## Roadmap

We are currently focusing on:

* Exploring new rendering technologies.

Future plans include:

* Improving stability and performance.
* Enhancing the mod installation experience.

We welcome community feedback and suggestions for our roadmap.  Please feel free to open a feature request in our [issue tracker](https://github.com/CopperLauncher/Copper-Android/issues).
