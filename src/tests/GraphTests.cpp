//
// Created by pcxie on 2020/11/27.
//
#include "gtest/gtest.h"
#include <limits>
#include "../Graph.h"
const double INF = std::numeric_limits<double>::infinity();

class GraphTests : public ::testing::Test {
protected:
    void SetUp() override{
        graph = *(new Graph(9));
        graph.insertEdge(0,1,4.0);
        graph.insertEdge(0,1,4.0);
        graph.insertEdge(0,7,8.0);
        graph.insertEdge(1,7,11.0);
        graph.insertEdge(1,2,8.0);
        graph.insertEdge(7,8,7.0);
        graph.insertEdge(7,6,1.0);
        graph.insertEdge(2,8,2.0);
        graph.insertEdge(8,6,6.0);
        graph.insertEdge(2,3,7.0);
        graph.insertEdge(2,5,4.0);
        graph.insertEdge(6,5,2.0);
        graph.insertEdge(3,5,14.0);
        graph.insertEdge(3,4,9.0);
        graph.insertEdge(5,4,10.0);
    }

    void TearDown() {
//        delete &graph;
    }

    double **getAdj(){
        return graph.adjMatrix;
    }
    Graph graph;
};

TEST_F(GraphTests,initGraphTest){
    graph.init();
    EXPECT_EQ(INF,getAdj()[0][0]);
}

TEST_F(GraphTests,getEdgeCountTest){
    EXPECT_EQ(14,graph.getEdgeCount());
    graph.rmEdge(0,1);
    graph.rmEdge(1,0);
    graph.rmEdge(7,0);
    graph.insertEdge(1,0,2.0);
    EXPECT_EQ(12,graph.getEdgeCount());
    graph.init();
    EXPECT_EQ(0,graph.getEdgeCount());
}