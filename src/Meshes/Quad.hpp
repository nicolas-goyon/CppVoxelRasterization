//
// Created by Nico on 5/19/2026.
//

#ifndef CPPVOXELRASTERIZATION_QUAD_HPP
#define CPPVOXELRASTERIZATION_QUAD_HPP
#include "../Math/Vector3.hpp"
#include <stdexcept>

namespace Meshes {
    struct Quad {
    public:
        // Constructors
        Quad();
        Quad(const Math::Vector3 *vertex,Math::Vector3 Normal, int ID);

        // Methods

        void SetVertex(int index,Math::Vector3 value);



        // Attributes

        // TODO : Check if in this project, a vector 3 is more suited than an int3 or equivalent
        /// Array of 4 values
        Math::Vector3 vertex[4];

        /// The "direction" the quad is facing
        Math::Vector3 Normal;

        /// Color/Material/Texture ID
        int ID;
    };
} // Meshes

#endif //CPPVOXELRASTERIZATION_QUAD_HPP
