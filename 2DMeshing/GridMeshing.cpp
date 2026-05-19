//
// Created by Nico on 5/19/2026.
//

#include "GridMeshing.hpp"

namespace Meshing2D {
    GridMeshing::~GridMeshing() {
        delete pixel_grid;
        delete mesh;
    }

    void GridMeshing::GreedyMeshingOptimisation() {
        int const lengthX = pixel_grid->GetSizeX();
        int const lengthY = pixel_grid->GetSizeY();

        std::vector<int> quadIds = std::vector<int>(lengthX * lengthY);

        int IDIndex = 0;
        for (int x = 0; x < lengthX; ++x) {
            for (int y = 0; y < lengthY; ++y) {
                quadIds[y * lengthX + x] = IDIndex;
                if (y < lengthY - 1 && pixel_grid->Get(x, y) == pixel_grid->Get(x, y + 1)) {
                    quadIds[(y + 1) * lengthX + x] = IDIndex;
                    ++y;
                }
                ++IDIndex;
            }
        }

        // Debug
        PixelGrid pix = PixelGrid(lengthX, lengthY);
        pix.Fill(
            [quadIds, lengthX](int x, int y) { return quadIds[y * lengthX + x]; }
        );
        std::cout << pix;
    }
} // Meshing2D
