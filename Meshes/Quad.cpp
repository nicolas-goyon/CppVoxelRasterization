//
// Created by Nico on 5/19/2026.
//

#include "Quad.hpp"
#include <stdexcept>

namespace Meshes {
    Quad::Quad() {
        vertex[0] = {0.,0.,0.};
        vertex[1] = {0.,0.,0.};
        vertex[2] = {0.,0.,0.};
        vertex[3] = {0.,0.,0.};

        Normal = {0,0,0};

        ID = 0;
    }

    Quad::Quad(const Math::Vector3 *vertex, const Math::Vector3 Normal, const int ID): Normal(Normal), ID(ID) {
        this->vertex[0] = vertex[0] ;
        this->vertex[1] = vertex[1] ;
        this->vertex[2] = vertex[2] ;
        this->vertex[3] = vertex[3] ;
    }

    void Quad::SetVertex(const int index, const Math::Vector3 value) {
        if (index < 0) throw std::invalid_argument("Negative index");
        if (index > 3) throw std::invalid_argument("Index Out of bound");

        this->vertex[index] = value;
    }
} // Meshes