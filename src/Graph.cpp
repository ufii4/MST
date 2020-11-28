//
// Created by pcxie on 2020/11/27.
//

#include <limits>
#include <algorithm>
#include "Graph.h"
#include "DisjointSet.h"
#include "SortingAlgorithms.h"

const double INF = std::numeric_limits<double>::infinity();

pair::pair(unsigned int x, unsigned int y, double weight) : x(x), y(y), weight(weight) {}

Graph::Graph(unsigned int numberOfNodes) : numberOfNodes(numberOfNodes) {
    adjMatrix = new double *[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++) {
        adjMatrix[i] = new double[numberOfNodes];
    }
    init();
}

Graph::~Graph() {
    for (int i = 0; i < numberOfNodes; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::init() {
    for (int i = 0; i < numberOfNodes; i++) {
        for (int j = 0; j < numberOfNodes; j++) {
            adjMatrix[i][j] = INF;
        }
    }
}

void Graph::insertEdge(unsigned int v1, unsigned int v2, double weight) {
    adjMatrix[v1][v2] = weight;
    adjMatrix[v2][v1] = weight;
}

bool Graph::rmEdge(unsigned int v1, unsigned int v2) {
    if (adjMatrix[v1][v2] != INF) {
        adjMatrix[v1][v2] = INF;
        adjMatrix[v2][v1] = INF;
        return true;
    } else {
        return false;
    }
}

unsigned int Graph::getEdgeCount() {
    unsigned int numberOfEdges = 0;
    for (int i = 0; i < numberOfNodes; i++) {
        for (int j = i; j < numberOfNodes; j++) {
            numberOfEdges += adjMatrix[i][j] != INF;
        }
    }
    return numberOfEdges;
}

unsigned int Graph::getDegreeOf(unsigned int vertex) {
    unsigned int degree = 0;
    for (int i = 0; i < numberOfNodes; i++) {
        degree += adjMatrix[vertex][i] != INF;
    }
    return degree;
}

bool Graph::tryGetMSTWeight(double &weight) {
    // Sort the matrix
    unsigned int n = numberOfNodes * numberOfNodes;
    pair set[n];
    for (unsigned int i = 0; i < numberOfNodes; i++) {
        for (unsigned int j = 0; j < numberOfNodes; j++) {
            set[i * numberOfNodes + j] = pair(i, j, adjMatrix[i][j]);
        }
    }
//    Using lambda expression to allow fast transformation from descending sort to ascending sort
    insertionSort<pair>(n, set, [](pair a, pair b) {
        return a.weight < b.weight;
    });

    DisjointSet DSet(numberOfNodes);
    weight = 0;
    int count = 0; // the number of edges counted
    for (int i = 0; i < n; i++) {
        pair p = set[i];
        if (p.weight==INF){
            break;
        }
        if (DSet.find(p.x) != DSet.find(p.y)) {
            count++;
            weight += p.weight;
            DSet.merge(p.x, p.y);
        }
    }
//    Same as there are nodes that the tree haven't been to, meaning that the graph is not connected.
    return count == numberOfNodes-1;
}

unsigned int Graph::getSize() {
    return numberOfNodes;
}
