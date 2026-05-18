//
// Created by nico_ on 5/18/2026.
//

#ifndef CPPVOXELRASTERIZATION_PIXELGRID_HPP
#define CPPVOXELRASTERIZATION_PIXELGRID_HPP

#include <vector>
#include <iostream>

namespace Meshing2D {
    class PixelGrid {
        public:
            PixelGrid(int sizeX, int sizeY);

            ~PixelGrid();

            [[nodiscard]] int Get(int x, int y) const;

            void Set(int x, int y, int value);

            /// @param predicate (int, int) -> int
            template <typename Predicate>
            void Fill(Predicate predicate) {
                for (int x = 0; x < sizeX; x++) {
                    for (int y = 0; y < sizeY; y++) {
                        grid[y * sizeX + x] = predicate(x, y);
                    }
                }
            }

            std::ostream& Display(std::ostream &flux) const;


        private:

            int sizeX;
            int sizeY;
            std::vector<int> grid;
    };

    inline std::ostream& operator<<( std::ostream &flux, PixelGrid const& grid)  {
        return grid.Display(flux);
    }
} // Meshing2D

#endif //CPPVOXELRASTERIZATION_PIXELGRID_HPP
