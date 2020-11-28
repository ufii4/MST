//
// Created by pcxie on 2020/11/28.
//
#include "gtest/gtest.h"
#include "../DisjointSet.h"

class DisjointSetTests : public ::testing::Test {
protected:
    void SetUp() override{
        set = DisjointSet(5);
    }

    void TearDown() {
//        delete &graph;
    }

    DisjointSet set;
};

TEST_F(DisjointSetTests, test1){
    EXPECT_EQ(1,set.find(1));
}