// Use the standard library header, but import our custom module
#include <iostream>
#include "Chunk.hpp"


int main()
{
    std::cout << "Hello World!\n";
    Chunk chunk(4, 4, 4);
    std::cout << chunk;
    return 0;
}