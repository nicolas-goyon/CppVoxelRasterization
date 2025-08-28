#pragma once

#include "Int3.hpp"

struct MeshQuad
{
    Int3 Vertex0; // bottom-left
    Int3 Vertex1; // bottom-right
    Int3 Vertex2; // top-right
    Int3 Vertex3; // top-left

    Int3 Normal;
    unsigned int VoxelID;
};
