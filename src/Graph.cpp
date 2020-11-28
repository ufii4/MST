//
// Created by pcxie on 2020/11/27.
//

#include <limits>
#include <algorithm>
#include "Graph.h"
#include "DisjointSet.h"
const double INF = std::numeric_limits<double>::infinity();

Graph::Graph(unsigned int numberOfNodes) : numberOfNodes(numberOfNodes) {
    adjMatrix = new double *[numberOfNodes];
    for (int i = 0; i < numberOfNodes; i++) {
        adjMatrix[i] = new double [numberOfNodes];
    }
    init();
}

Graph::~Graph() {
//    for (int i = 0; i < numberOfNodes; i++) {
//        delete[] adjMatrix[i];
//    }
    delete[] adjMatrix;
}

void Graph::init() {
    for (int i = 0; i < numberOfNodes; i++) {
        for (int j = 0; j < numberOfNodes; j++) {
            adjMatrix[i][j] = INF;
        }
    }
}

bool Graph::insertEdge(unsigned int v1, unsigned int v2, double weight) {
    if (adjMatrix[v1][v2] == INF){
        adjMatrix[v1][v2] = weight;
        adjMatrix[v2][v1] = weight;
        return true;
    }else{
        return false;
    }
}

bool Graph::rmEdge(unsigned int v1, unsigned int v2) {
    if (adjMatrix[v1][v2] != INF){
        adjMatrix[v1][v2] = INF;
        adjMatrix[v2][v1] = INF;
        return true;
    }else{
        return false;
    }
}

unsigned int Graph::getEdgeCount() {
    unsigned int numberOfEdges = 0;
    for (int i = 0; i < numberOfNodes; i++) {
        for (int j = i; j < numberOfNodes; j++) {
            numberOfEdges += adjMatrix[i][j]!=INF;
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

double Graph::getMSTWeight() {
    DisjointSet DJSet(numberOfNodes);
    double weight;
    std::sort(adjMatrix[0][0],adjMatrix[numberOfNodes][numberOfNodes]);
    return 0;
}
