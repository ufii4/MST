//
// Created by pcxie on 2020/11/27.
//

#include "Graph.h"

Edge::Edge(int n1, int n2, double weight) : n1(n1), n2(n2), weight(weight) {}

Graph::Graph(unsigned int n) : n(n) {
    nodes = new Node[n][n];
}
