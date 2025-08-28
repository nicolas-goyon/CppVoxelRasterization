
#include <iostream>
#include <cstdlib>
#include <format>
#include "TwoDArray.h"

TwoDArray::TwoDArray(int sizeX, int sizeY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->data = new int[sizeX * sizeY]; // TODO : add delete or use std::unique_ptr
}

void TwoDArray::randFill()
{
    for (int x = 0; x < sizeX; x++)
    {
        for (int y = 0; y < sizeY; y++)
        {
            int randomNumber = std::rand() % 101;
            data[x * sizeX + y] = randomNumber;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const TwoDArray &p)
{
    os << "I am a 2D array of size : " << p.sizeX << " x " << p.sizeY << " \n";
    os << "\n";
    os << "|";
    for (int i = 0; i < p.sizeX; i++)
    {
        os << "----";
    }
    os << "|\n";
    for (int y = 0; y < p.sizeY; y++)
    {
        os << "|";
        for (int x = 0; x < p.sizeX; x++)
        {
            os << std::format("{:<4}", p.data[x * p.sizeX + y]);
        }
        os << "|\n";
    }
    os << "|";
    for (int i = 0; i < p.sizeX; i++)
    {
        os << "----";
    }
    os << "|\n";
    return os;
}