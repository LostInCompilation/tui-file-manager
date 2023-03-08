//
//  Main.h
//  tui-file-manager
//
//  Created by Marc Schöndorf on 07.03.23.
//

#ifndef Main_h
#define Main_h

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
// Version
#define TUIFM_VERSION_MAJOR 0
#define TUIFM_VERSION_MINOR 1
#define TUIFM_VERSION_REVISION 0

//***********************************************************************
// Includes
// System
#include <iostream>
#include <filesystem>

// FTXUI
#include "ftxui/component/screen_interactive.hpp"   // for Component, ScreenInteractive
#include "ftxui/component/component.hpp"            // for Menu, Horizontal, Renderer

// CLI11
#include "CLI11.hpp"

// Project
#include "UI.h"

#endif /* Main_h */
