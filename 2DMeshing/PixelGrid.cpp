//
// Created by nico_ on 5/18/2026.
//

#include "PixelGrid.hpp"

namespace Meshing2D {

    PixelGrid::PixelGrid(int const sizeX, int const sizeY) : sizeX(sizeX), sizeY(sizeY), grid(sizeX * sizeY){    }

    PixelGrid::PixelGrid(PixelGrid &other) :sizeX(other.sizeX), sizeY(other.sizeY), grid(sizeX*sizeY) {
        this->Fill(
            [&other](int const x,int const y) {return other.Get(x,y);}
            );
    }

    PixelGrid::~PixelGrid() = default;

    int PixelGrid::Get(const int x, const int y) const {
        return grid[y * sizeX + x];
    }

    void PixelGrid::Set(const int x, const int y, const int value) {
        grid[y * sizeX + x] = value;
    }

    std::ostream& PixelGrid::Display(std::ostream &flux) const {
        for (int x = 0; x < sizeX; x++) {
            flux << "|";
            for (int y = 0; y < sizeY; y++) {
                int const value = grid[y * sizeX + x];
                if (value > 100) flux << value;
                else if (value >= 10) flux << value << " ";
                else flux << " " << value << " ";
                flux << "|";
            }
            flux << std::endl;
            for (int y = 0; y < sizeY; y++) {
                flux << "----";
            }
            flux << std::endl;
        }

        return flux;
    }
}