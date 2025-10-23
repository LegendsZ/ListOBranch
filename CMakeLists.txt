cmake_minimum_required(VERSION 3.15)
project(ListOBranch)

option(LISTOBRANCH_BUILD_SHARED "Build ListOBranch as a shared library" ON)

add_subdirectory(src)
add_subdirectory(terminal)
add_subdirectory(gui)