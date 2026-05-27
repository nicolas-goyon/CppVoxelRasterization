//
// Created by Nico on 5/27/2026.
//

#ifndef CPPVOXELRASTERIZATION_GUARD_HPP
#define CPPVOXELRASTERIZATION_GUARD_HPP
#include <cstddef>


namespace  Guard {
    /**
     * @param value Value to check
     * @param low Lowest value that @code value@endcode can be
     * @param high Highest value that @code value@endcode can be
     */
    static void IsInRange(int value, int low, int high);



    /**
     * @param value Value to check
     * @param low Minimum value (inclusive)
     */
    static void IsAbove(int value, int low);

    /**
     * @param value Value to check
     * @param high Maximum value (inclusive)
     */
    static void IsBelow(int value, int high);

    /**
     * @param value Value to check — throws if value <= 0
     */
    static void IsPositive(int value);

    /**
     * @param ptr Pointer to check — throws if null
     */
    static void IsNotNull(void* ptr);

};
#endif //CPPVOXELRASTERIZATION_GUARD_HPP
