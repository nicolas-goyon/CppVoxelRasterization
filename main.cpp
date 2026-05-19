#include <iostream>

#include "2DMeshing/GridMeshing.hpp"
#include "2DMeshing/PixelGrid.hpp"

using namespace std;




int main() {
    std::cout << "Hello, World!" << std::endl;

    Meshing2D::PixelGrid pix = Meshing2D::PixelGrid(5, 6);

    pix.Fill(
        [](int x, int y) {return (rand() %100 > 50) ? 1:0;}
    );

    std::cout << pix << std::endl;

    Meshing2D::GridMeshing mesher = Meshing2D::GridMeshing(&pix);

    mesher.GreedyMeshingOptimisation();

    return 0;
}
