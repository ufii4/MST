//
// Created by pcxie on 2020/12/3.
//

#ifndef MST_DISJOINTSET_H
#define MST_DISJOINTSET_H


class DisjointSet {
public:
    DisjointSet() = default;

    DisjointSet(unsigned int n);

    ~DisjointSet();

    void merge(unsigned int i1, unsigned int i2);

    unsigned int find(unsigned int x);

private:
    unsigned int n = 0;
    unsigned int *nodes = nullptr;
};


#endif //MST_DISJOINTSET_H
