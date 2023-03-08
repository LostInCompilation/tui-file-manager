cmake_minimum_required(VERSION 3.15)

# Our project
project("tui-file-manager"
	LANGUAGES CXX
)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Main executable
add_executable("${PROJECT_NAME}"
	src/Main.cpp
	src/UI.cpp
)

# The project include dir
target_include_directories("${PROJECT_NAME}" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")


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
