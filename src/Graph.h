//
// Created by pcxie on 2020/11/27.
//

#ifndef MST_GRAPH_H
#define MST_GRAPH_H

//The struct pair is used to represent the relationship between two nodes in the graph
struct pair {
    pair() = default;

    pair(unsigned int x, unsigned int y, double weight);

    unsigned int x, y;
    double weight;
};

class Graph {
    friend class GraphTests;
protected:
    unsigned int numberOfNodes;
    double **adjMatrix;
public:
    Graph() = default;

    Graph(unsigned int numberOfNodes);

    ~Graph();

    void init();

    void insertEdge(unsigned int v1, unsigned int v2, double weight);

    bool rmEdge(unsigned int v1, unsigned int v2);

    unsigned int getEdgeCount();

    unsigned int getDegreeOf(unsigned int vertex);

    bool tryGetMSTWeight(double &weight);

    unsigned int getSize();
};


#endif //MST_GRAPH_H
