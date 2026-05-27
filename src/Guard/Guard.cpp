//
// Created by Nico on 5/27/2026.
//

#include "Guard.hpp"

#include <format>
#include <stdexcept>

namespace Guard {
    void IsInRange(int value, int low, int high) {
        if (value < low or value > high) throw std::out_of_range(std::format("Value ({}) was out of bounds ({} : {}) ", value, low, high));
    }


    void IsAbove(int value, int low) {
        if (value < low) throw std::out_of_range(std::format("Value ({}) was below minimum ({})", value, low));
    }

    void IsBelow(int value, int high) {
        if (value > high) throw std::out_of_range(std::format("Value ({}) was above maximum ({})", value, high));
    }

    void IsPositive(int value) {
        if (value <= 0) throw std::out_of_range(std::format("Value ({}) must be strictly positive", value));
    }

    void IsNotNull(void* ptr) {
        if (ptr == nullptr) throw std::invalid_argument("Pointer must not be null");
    }
}
