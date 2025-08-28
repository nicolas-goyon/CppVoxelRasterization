#include "Chunk.hpp"



Chunk::Chunk(unsigned int xDepth, unsigned int yDepth, unsigned int zDepth){
    this->XDepth = xDepth;
    this->YDepth = yDepth;
    this->ZDepth = zDepth;

    this->data = new Voxel[xDepth * yDepth * zDepth];
}
Chunk::~Chunk(){
    delete data;
    delete XDepth;
    delete YDepth;
    delete ZDepth;
}

    
bool Chunk::IsOutOfBound(unsigned int x, unsigned int y, unsigned int z){
    return x < this->XDepth && y < this->YDepth && z < this->ZDepth;
}


std::ostream &operator<<(std::ostream &os, const Chunk &chunk){
    os << "Chunk size (x:" << chunk.XDepth << " - y:" << chunk.YDepth << " - z:" << chunk.ZDepth << ")\n";
    return os;
}