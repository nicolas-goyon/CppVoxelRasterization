cmake_minimum_required(VERSION 4.2)
project(CppVoxelRasterization)

set(CMAKE_CXX_STANDARD 20)

add_executable(CppVoxelRasterization main.cpp
        2DMeshing/PixelGrid.cpp
        2DMeshing/PixelGrid.hpp)
