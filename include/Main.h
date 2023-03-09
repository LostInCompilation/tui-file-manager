//
//  Main.h
//  tui-file-manager
//
//  Created by Marc Schöndorf on 07.03.23.
//

#ifndef Main_h
#define Main_h

//***********************************************************************
// System includes
#include <iostream>
#include <filesystem>

//***********************************************************************
// Determine the target OS
#if !defined(TARGET_OS_UNIX) && !defined(TARGET_OS_MAC) && !defined(TARGET_OS_WINDOWS)
    #if (__linux__) || (__unix__)  || (__unix)
        #define TARGET_OS_UNIX
    #elif (__APPLE__ && __MACH__)
        #define TARGET_OS_MAC
    #elif _WIN32 // For Win32 and Win64
        #define TARGET_OS_WINDOWS
    #else
        #error The target OS is unsupported. If you believe your OS is compatible with tui-file-manager, manually define one of the following macros: TARGET_OS_UNIX, TARGET_OS_MAC, TARGET_OS_WINDOWS
    #endif
#endif

//***********************************************************************
// Info
const int32_t TUIFM_VERSION_MAJOR = 0;
const int32_t TUIFM_VERSION_MINOR = 1;
const int32_t TUIFM_VERSION_REVISION = 0;
const std::string TUIFM_VERSION_STRING = "v" + std::to_string(TUIFM_VERSION_MAJOR) + "." + std::to_string(TUIFM_VERSION_MINOR) + "." + std::to_string(TUIFM_VERSION_REVISION);

const std::string TUIFM_APP_NAME = "tui-file-manager";
const std::string TUIFM_APP_DESCRIPTION = "A file manager for your terminal with a nice GUI.";

//***********************************************************************
// Project includes
// FTXUI
#include "ftxui/component/screen_interactive.hpp"   // for Component, ScreenInteractive
#include "ftxui/component/component.hpp"            // for Menu, Horizontal, Renderer

// CLI11
#include "CLI/CLI.hpp"

// Project
#include "UI.h"

#endif /* Main_h */
