cmake_minimum_required(VERSION 3.11)

project("tui-file-manager"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)


add_executable("${PROJECT_NAME}"
	src/Main.cpp
	src/UI.cpp
)

target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

