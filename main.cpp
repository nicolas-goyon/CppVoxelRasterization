#include <iostream>
#include "2DMeshing/PixelGrid.hpp"

using namespace std;


class PixelGridFiller {
    public:
    int operator()(int x, int y) const {
        return x * y;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;

    PixelGridFiller predicate;
    Meshing2D::PixelGrid pix = Meshing2D::PixelGrid(5, 6);

    pix.Fill(predicate);

    std::cout << pix << std::endl;

    return 0;
}
