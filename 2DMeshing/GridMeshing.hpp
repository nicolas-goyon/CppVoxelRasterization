//
// Created by Nico on 5/19/2026.
//

#ifndef CPPVOXELRASTERIZATION_GRIDMESHING_HPP
#define CPPVOXELRASTERIZATION_GRIDMESHING_HPP
#include "PixelGrid.hpp"
#include "../Meshes/Mesh.hpp"

namespace Meshing2D {

class GridMeshing {
public :
    GridMeshing(const PixelGrid *pixel_grid): pixel_grid(pixel_grid){}

    ~GridMeshing();


    void GreedyMeshingOptimisation();

    [[nodiscard]] bool HasMesh() const {return mesh == nullptr;};

private:
    const PixelGrid *pixel_grid;

    Meshes::Mesh *mesh = nullptr;

};

} // Meshing2D

#endif //CPPVOXELRASTERIZATION_GRIDMESHING_HPP
