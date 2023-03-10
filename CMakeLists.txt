cmake_minimum_required(VERSION 3.24)

# Diagnostics
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
#variable_watch(CMAKE_BUILD_TYPE)

#set(CMAKE_OSX_DEPLOYMENT_TARGET "12.0" CACHE STRING "Minimum OS X deployment version")

###########################################################
# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS false)

###########################################################
# Set options for libs
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW) # Needed to set options in subprojects from here

set(FTXUI_BUILD_DOCS OFF)
set(FTXUI_BUILD_EXAMPLES OFF)
set(FTXUI_ENABLE_INSTALL OFF)

set(CLI11_PRECOMPILED ON)

###########################################################
# Our project
project("tui-file-manager"
	VERSION 0.1.0
	DESCRIPTION "A file manager for your terminal with a nice GUI"
	LANGUAGES CXX
)

# Main executable
add_executable("${PROJECT_NAME}"
	include/Main.h
	include/FileManagerUI.h
	src/Main.cpp
	src/FileManagerUI.cpp
)

# The projects include directories
target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

###########################################################
# Project versioning
configure_file(TUIFMConfig.h.in TUIFMConfig.h)
target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")

###########################################################
# Use FTXUI lib
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/ftxui")

target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/ftxui/include")
target_link_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/lib/ftxui")
target_link_libraries("${PROJECT_NAME}"
	PRIVATE screen
	PRIVATE dom
	PRIVATE component
)

###########################################################
# Use CLI11 lib
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/lib/CLI11")

target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/CLI11/include")
target_link_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/lib/CLI11/src")
target_link_libraries("${PROJECT_NAME}"
	PRIVATE CLI11
)

#############################################################
#target_compile_options("${PROJECT_NAME}" PRIVATE "-O3")

###########################################################
# Add as many warning as possible
if (WIN32)
	if (MSVC)
		target_compile_options("${PROJECT_NAME}" PRIVATE "/W3")
		target_compile_options("${PROJECT_NAME}" PRIVATE "/WX")
		target_compile_options("${PROJECT_NAME}" PRIVATE "/wd4244")
		target_compile_options("${PROJECT_NAME}" PRIVATE "/wd4267")
		target_compile_options("${PROJECT_NAME}" PRIVATE "/D_CRT_SECURE_NO_WARNINGS")
	endif()
	# Force Win32 to UNICODE
	target_compile_definitions("${PROJECT_NAME}" PRIVATE UNICODE _UNICODE)
else()
	target_compile_options("${PROJECT_NAME}" PRIVATE "-Wall")
	target_compile_options("${PROJECT_NAME}" PRIVATE "-Wsign-conversion")
	#add_compile_options("-Weverything")
	#add_compile_options("-Wsign-conversion")
	target_compile_options("${PROJECT_NAME}" PRIVATE "-Wextra")
	target_compile_options("${PROJECT_NAME}" PRIVATE "-pedantic")
	#target_compile_options("${PROJECT_NAME}" PRIVATE "-Werror")
	target_compile_options("${PROJECT_NAME}" PRIVATE "-Wmissing-declarations")
	target_compile_options("${PROJECT_NAME}" PRIVATE "-Wdeprecated")
	target_compile_options("${PROJECT_NAME}" PRIVATE "-Wshadow")
endif()

