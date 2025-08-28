// Use the standard library header, but import our custom module
#include <iostream>
#include "TwoDArray.h"
#include "main2.cpp"

int main()
{
    std::cout << "Hello World!\n";
    TwoDArray newArray(10, 12);
    newArray.randFill();
    std::cout << newArray;
    main2();
    return 0;
}