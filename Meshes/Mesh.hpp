//
// Created by Nico on 5/19/2026.
//

#ifndef CPPVOXELRASTERIZATION_MESH_HPP
#define CPPVOXELRASTERIZATION_MESH_HPP
#include <list>

#include "Quad.hpp"

namespace Meshes {
    class Mesh {
    public:


    private:
        // Liste de quads/rectangles : Un quad = 2 triangles
        std::list<Quad> quads;
    };
} // Meshes

#endif //CPPVOXELRASTERIZATION_MESH_HPP
