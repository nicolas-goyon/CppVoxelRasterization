#pragma once

class TwoDArray
{
private:
    int sizeX;
    int sizeY;
    int *data;

public:
    TwoDArray(int sizeX, int sizeY);
    void randFill();
    friend std::ostream &operator<<(std::ostream &os, const TwoDArray &p);
};