cmake_minimum_required(VERSION 4.2)
project(CppVoxelRasterization)

set(CMAKE_CXX_STANDARD 20)

add_executable(CppVoxelRasterization src/main.cpp
        src/2DMeshing/PixelGrid.cpp
        src/2DMeshing/PixelGrid.hpp
        src/Toolkit/ObjExporter.cpp
        src/Toolkit/ObjExporter.hpp
        src/Meshes/Mesh.cpp
        src/Meshes/Mesh.hpp
        src/Meshes/Quad.cpp
        src/Meshes/Quad.hpp
        src/Math/Vector3.cpp
        src/Math/Vector3.hpp
        src/Math/Quaternion.cpp
        src/Math/Quaternion.hpp
        src/2DMeshing/GridMeshing.cpp
        src/2DMeshing/GridMeshing.hpp
        src/Core/DisjointSet.cpp
        src/Core/DisjointSet.hpp
        src/Guard/Guard.cpp
        src/Guard/Guard.hpp
)
