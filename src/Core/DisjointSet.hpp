//
// Created by Nico on 5/27/2026.
//

#ifndef CPPVOXELRASTERIZATION_DISJOINTSET_HPP
#define CPPVOXELRASTERIZATION_DISJOINTSET_HPP
#include <vector>

namespace Core {
    class DisjointSet {
    public:

        /**
            * Initializes an empty union-find data structure with
            * {@code n} elements {@code 0} through {@code n-1}.
            * Initially, each element is in its own set.
            *
            * @param  n the number of elements
            * @throws an exception if {@code n < 0}
            */
        DisjointSet(int n);
        /**
            * Returns the number of sets.
            *
            * @return the number of sets (between {@code 1} and {@code n})
            */
        [[nodiscard]] int Count() const;

        bool IsRoot(int p);

        /**
        * Returns the canonical element of the set containing element @code p@endcode
        *
        * @param  p an element
        * @return the canonical element of the set containing @code p@endcode
        * @throws an exception unless @code p   0 <= p < n@endcode
        */
        int Find(int p);

        /**
        * Merges the set containing element @code p@endcode with the set
        * containing element @code q@endcode.
        *
        * @param  p one element
        * @param  q the other element
        * @throws an exception unless
        *         both @code p   0 <= p < n@endcode and @code p   0 <= q < n@endcode
        */
        void Union(int p, int q);

    private:
        std::vector<int> parent;
        std::vector<int> size;
        int count;
    };
} // Core

#endif //CPPVOXELRASTERIZATION_DISJOINTSET_HPP
