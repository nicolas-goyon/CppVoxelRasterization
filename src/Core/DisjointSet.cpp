//
// Created by Nico on 5/27/2026.
//

#include "DisjointSet.hpp"

#include <stdexcept>
#include <bits/error_constants.h>

#include "../Guard/Guard.hpp"

namespace Core {
    DisjointSet::DisjointSet(const int n) {
        if (n <= 0 ) throw std::invalid_argument("The size of n should be > 0");

        count = n;
        parent = std::vector<int>(n);
        size = std::vector<int>(n);
    }

    int DisjointSet::Count() const {
        return count;
    }

    bool DisjointSet::IsRoot(int p) {
        return parent[p] = p;
    }

    int DisjointSet::Find(int p) {
        int const max = static_cast<int>(parent.size()); // FIXME : Parent size shouldn't be over max int, but it's not perfect
        Guard::IsInRange(p, 0 ,max);

        int root = p;
        while (root != parent[root])
            root = parent[root];

        while (p !=root) {
            const int newP = parent[p];
            parent[p] = root;
            p = newP;
        }

        return root;
    }

    void DisjointSet::Union(int p, int q) {
        int const rootP = Find(p);
        int const rootQ = Find(q);

        if (rootP == rootQ) return;

        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }
} // Core
