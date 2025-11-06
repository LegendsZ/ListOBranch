cmake_minimum_required(VERSION 3.16)
project(ListOBranch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Always build the core library
add_subdirectory(src)

# Optional subprojects
option(LOB_DEBUG "Enable ListOBranch debug mode" OFF)
option(BUILD_TERMINAL "Build terminal CLI interface" OFF)
option(BUILD_GUI "Build GUI interface" OFF)

if(LOB_DEBUG)
    add_compile_definitions(LOB_DEBUG_MODE=1)
else()
    add_compile_definitions(LOB_DEBUG_MODE=0)
endif()

if(BUILD_TERMINAL)
    add_subdirectory(terminal)
endif()

if(BUILD_GUI)
    add_subdirectory(gui)
endif()