//
// Created by pcxie on 2020/11/27.
//

#include "DisjointSet.h"

DisjointSet::DisjointSet(unsigned int n) : n(n) {
    nodes = new unsigned int[n];
}

void DisjointSet::merge(unsigned int i1, unsigned int i2) {
    nodes[find(i1)] = nodes[find(i2)];
}

// x<n
unsigned int DisjointSet::find(unsigned int x) {
    return x == nodes[x] ? x : (find(nodes[x]));
}
