//
// Created by pcxie on 2020/11/27.
//

#ifndef MST_GRAPH_H
#define MST_GRAPH_H

struct Edge{
    Edge() = default;

    Edge(int n1, int n2, double weight);

    int n1;
    int n2;
    double weight;
};

struct Node{
    int key;
};

class Graph {
private:
    unsigned int n;
    double **adj;
    Node *nodes;
    Edge *edges;
public:
    Graph() = default;

    Graph(unsigned int n);

};


#endif //MST_GRAPH_H
