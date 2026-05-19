cmake_minimum_required(VERSION 4.2)
project(CppVoxelRasterization)

set(CMAKE_CXX_STANDARD 20)

add_executable(CppVoxelRasterization main.cpp
        2DMeshing/PixelGrid.cpp
        2DMeshing/PixelGrid.hpp
        Toolkit/ObjExporter.cpp
        Toolkit/ObjExporter.hpp
        Meshes/Mesh.cpp
        Meshes/Mesh.hpp
        Meshes/Quad.cpp
        Meshes/Quad.hpp
        Math/Vector3.cpp
        Math/Vector3.hpp
        Math/Quaternion.cpp
        Math/Quaternion.hpp
        2DMeshing/GridMeshing.cpp
        2DMeshing/GridMeshing.hpp
)
