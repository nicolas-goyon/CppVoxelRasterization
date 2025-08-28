// Use the standard library header, but import our custom module
#include <iostream>
#include "TwoDArray.h"

int main2()
{
    std::cout << "Hello World!\n";
    TwoDArray newArray(10, 12);
    newArray.randFill();
    std::cout << newArray;
    return 0;
}