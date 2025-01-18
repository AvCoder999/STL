#include "headers/PriorityQueue.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <list>

TEST(PriorityQueue, Lesstest)
{
    PriorityQueue<int, std::vector<int>, std::less<int> > pq;
    pq.push(1);
    EXPECT_EQ(pq.top(), 1);

    pq.push(2);
    EXPECT_EQ(pq.top(), 2);

    pq.push(5);
    EXPECT_EQ(pq.top(), 5);

    pq.push(3);
    EXPECT_EQ(pq.top(), 5);

    pq.push(9);
    EXPECT_EQ(pq.top(), 9);

    pq.push(0);
    EXPECT_EQ(pq.top(), 9);

    pq.push(3);
    EXPECT_EQ(pq.top(), 9);

    pq.push(4);
    EXPECT_EQ(pq.top(), 9);

    /// poping
    pq.pop();
    EXPECT_EQ(pq.top(), 5);

    pq.pop();
    EXPECT_EQ(pq.top(), 4);

    pq.pop();
    EXPECT_EQ(pq.top(), 3);

    pq.pop();
    EXPECT_EQ(pq.top(), 3);

    pq.pop();
    EXPECT_EQ(pq.top(), 2);

    pq.pop();
    EXPECT_EQ(pq.top(), 1);

    pq.pop();
    EXPECT_EQ(pq.top(), 0);
    
    pq.pop();
    EXPECT_TRUE(pq.empty());
}

TEST(PriorityQueue, Greatertest)
{
    PriorityQueue<int, std::vector<int>, std::greater<int> > pq;
    pq.push(1);
    EXPECT_EQ(pq.top(), 1);

    pq.push(2);
    EXPECT_EQ(pq.top(), 1);

    pq.push(5);
    EXPECT_EQ(pq.top(), 1);

    pq.push(3);
    EXPECT_EQ(pq.top(), 1);

    pq.push(9);
    EXPECT_EQ(pq.top(), 1);

    pq.push(0);
    EXPECT_EQ(pq.top(), 0);

    pq.push(3);
    EXPECT_EQ(pq.top(), 0);

    pq.push(4);
    EXPECT_EQ(pq.top(), 0);

    /// poping
    pq.pop();
    EXPECT_EQ(pq.top(), 1);

    pq.pop();
    EXPECT_EQ(pq.top(), 2);

    pq.pop();
    EXPECT_EQ(pq.top(), 3);

    pq.pop();
    EXPECT_EQ(pq.top(), 3);

    pq.pop();
    EXPECT_EQ(pq.top(), 4);

    pq.pop();
    EXPECT_EQ(pq.top(), 5);

    pq.pop();
    EXPECT_EQ(pq.top(), 9);
    
    pq.pop();
    EXPECT_TRUE(pq.empty());
}

TEST(PriorityQueue, test)
{
    PriorityQueue<int> Q;
    Q.push(1);
    Q.push(4);
    Q.push(2);
    Q.push(8);
    Q.push(5);
    Q.push(7);

    EXPECT_TRUE(Q.size() == 6);

    EXPECT_TRUE(Q.top() == 8);
    Q.pop();

    EXPECT_TRUE(Q.top() == 7);
    Q.pop();

    EXPECT_TRUE(Q.top() == 5);
    Q.pop();

    EXPECT_TRUE(Q.top() == 4);
    Q.pop();

    EXPECT_TRUE(Q.top() == 2);
    Q.pop();

    EXPECT_TRUE(Q.top() == 1);
    Q.pop();

    EXPECT_TRUE(Q.empty());
}

TEST(PriorityQueue, Ctortest1)
{
    const int size = 6;
    int v[size] = {1, 4, 2, 8, 5, 7};
    PriorityQueue<int> Q(v, v + size);
    
    EXPECT_TRUE(Q.size() == 6);

    EXPECT_TRUE(Q.top() == 8);
    Q.pop();

    EXPECT_TRUE(Q.top() == 7);
    Q.pop();

    EXPECT_TRUE(Q.top() == 5);
    Q.pop();

    EXPECT_TRUE(Q.top() == 4);
    Q.pop();

    EXPECT_TRUE(Q.top() == 2);
    Q.pop();

    EXPECT_TRUE(Q.top() == 1);
    Q.pop();

    EXPECT_TRUE(Q.empty());
}

TEST(PriorityQueue, Ctortest2)
{
    std::list<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);

    PriorityQueue<int> Q(v.begin(), v.end());
    EXPECT_TRUE(Q.size() == 6);

    EXPECT_TRUE(Q.top() == 8);
    Q.pop();

    EXPECT_TRUE(Q.top() == 7);
    Q.pop();

    EXPECT_TRUE(Q.top() == 5);
    Q.pop();

    EXPECT_TRUE(Q.top() == 4);
    Q.pop();

    EXPECT_TRUE(Q.top() == 2);
    Q.pop();

    EXPECT_TRUE(Q.top() == 1);
    Q.pop();

    EXPECT_TRUE(Q.empty());
}

TEST(PriorityQueue, Ctortest)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(8);
    v.push_back(5);
    v.push_back(7);

    PriorityQueue<int> Q(v.begin(), v.end());
    EXPECT_TRUE(Q.size() == 6);

    EXPECT_TRUE(Q.top() == 8);
    Q.pop();

    EXPECT_TRUE(Q.top() == 7);
    Q.pop();

    EXPECT_TRUE(Q.top() == 5);
    Q.pop();

    EXPECT_TRUE(Q.top() == 4);
    Q.pop();

    EXPECT_TRUE(Q.top() == 2);
    Q.pop();

    EXPECT_TRUE(Q.top() == 1);
    Q.pop();

    EXPECT_TRUE(Q.empty());
}


int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

