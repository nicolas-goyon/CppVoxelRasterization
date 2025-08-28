#pragma once

#include <ostream>
#include "Voxel.hpp"

class Chunk
{
private:
    
public:
    unsigned int XDepth;
    unsigned int YDepth;
    unsigned int ZDepth;

    Voxel* data; // Array of all voxels


    Chunk(unsigned int xDepth, unsigned int yDepth, unsigned int zDepth);
    ~Chunk();

    
    bool IsOutOfBound(unsigned int x, unsigned int y, unsigned int z);


    friend std::ostream &operator<<(std::ostream &os, const Chunk &p);
};
