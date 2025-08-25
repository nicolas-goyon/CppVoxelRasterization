#include <iostream>
using namespace std;

#include TwoDArray;


int main()
{
    printf("Hello World!\n");
    TwoDArray newArray = TwoDArray(10, 12);
    newArray.randFill();
    cout << newArray;
    return 0;
}