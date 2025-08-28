// Use the standard library header, but import our custom module
#include <iostream>
#include <algorithm>   // std::clamp
#include <cstdint>
#include <cmath>
#include <random>
#include "Chunk.hpp"

class PerlinNoise
{
public:
    PerlinNoise(unsigned int seed = 0)
    {
        int perm[256];
        for (int i = 0; i < 256; ++i)
            perm[i] = permutation[i];

        if (seed != 0)
        {
            std::mt19937 rng(seed);
            for (int i = 0; i < 256; ++i)
            {
                std::uniform_int_distribution<int> dist(i, 255);
                int swapIndex = dist(rng);
                std::swap(perm[i], perm[swapIndex]);
            }
        }

        for (int i = 0; i < 256; ++i)
        {
            p[i] = perm[i];
            p[256 + i] = perm[i];
        }
    }

    ~PerlinNoise(){
        // delete[] p;
        // delete[] permutation;
    }

    float Noise(float x, float y) const
    {
        int X = static_cast<int>(std::floor(x)) & 255;
        int Y = static_cast<int>(std::floor(y)) & 255;

        x -= std::floor(x);
        y -= std::floor(y);

        float u = Fade(x);
        float v = Fade(y);

        int A = p[X] + Y;
        int B = p[X + 1] + Y;

        float res = Lerp(v,
                         Lerp(u, Grad(p[A], x, y),
                              Grad(p[B], x - 1.0f, y)),
                         Lerp(u, Grad(p[A + 1], x, y - 1.0f),
                              Grad(p[B + 1], x - 1.0f, y - 1.0f)));

        return (res + 1.0f) * 0.5f; // map from [-1,1] to [0,1]
    }

private:
    int p[512];

    inline static const int permutation[256] = {
        151, 160, 137, 91, 90, 15,
        131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23,
        190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33,
        88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166,
        77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244,
        102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196, 135,
        130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5,
        202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42,
        223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43, 172, 9,
        129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228,
        251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
        49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254,
        138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180};

    static inline float Fade(float t)
    {
        return t * t * t * (t * (t * 6.0f - 15.0f) + 10.0f);
    }

    static inline float Lerp(float t, float a, float b)
    {
        return a + t * (b - a);
    }

    static inline float Grad(int hash, float x, float y)
    {
        int h = hash & 3;
        float u = (h < 2) ? x : y;
        float v = (h < 2) ? y : x;
        return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
    }
};


static inline int Index3D(unsigned int x, unsigned int y, unsigned int z,
                                  unsigned int X, unsigned int Y, unsigned int Z)
{
    return x + X * (y +  Y * z);
}

void FillWithPerlin(unsigned int seed, Chunk* chunk)
{
    // zero everything first
    const std::size_t total = static_cast<std::size_t>(chunk->XDepth) * chunk->YDepth * chunk->ZDepth;
    for (std::size_t i = 0; i < total; ++i) {
        chunk->data[i] = Voxel{};            // if Voxel is uint16_t this sets 0; if a struct, this default-constructs
    }

    PerlinNoise noise(seed);

    for (unsigned x = 0; x < chunk->XDepth; ++x) {
        for (unsigned z = 0; z < chunk->ZDepth; ++z) {
            // Normalize like your C# code did. If XDepth==ZDepth, this is identical.
            float nx = x / (float)chunk->XDepth;
            float nz = z / (float)chunk->ZDepth;

            // Same three octaves and weights
            float height =
                noise.Noise(nx * 1.0f, nz * 1.0f) * 20.0f +
                noise.Noise(nx * 2.0f, nz * 2.0f) * 10.0f +
                noise.Noise(nx * 4.0f, nz * 4.0f) *  5.0f;

            int h = std::clamp(static_cast<int>(height + 5.0f), 0,
                               static_cast<int>(chunk->YDepth) - 1);

            for (int y = 0; y <= h; ++y) {
                std::size_t idx = Index3D(x, y, z,
                                          chunk->XDepth, chunk->YDepth, chunk->ZDepth);
                chunk->data[idx].VoxelID = 1;
            }
            for (int y = h + 1; y < chunk->YDepth; y++){
                std::size_t idx = Index3D(x, y, z,
                                          chunk->XDepth, chunk->YDepth, chunk->ZDepth);
                chunk->data[idx].VoxelID = 0;
            }
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
    Chunk chunk(4, 2, 6);

    FillWithPerlin(123, &chunk);

    std::cout << chunk;

    return 0;
}