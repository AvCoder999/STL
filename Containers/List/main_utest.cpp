#include "headers/List.hpp"
#include <gtest/gtest.h>
#include <list>
#include <sstream>

TEST(ListDataStructure, CyclicListTest)
{
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    List<int>::const_iterator it = a.begin();
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(*it++, 3);
    EXPECT_EQ(*it++, 4);
    EXPECT_EQ(*it++, 5);
    EXPECT_EQ(*it++, 0);
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(*it++, 3);
    EXPECT_EQ(*it++, 4);
    EXPECT_EQ(*it++, 5);
    EXPECT_EQ(*it++, 0);
    EXPECT_EQ(*it++, 1);

    List<int>::const_iterator jt = --a.end();
    EXPECT_EQ(*jt--, 5);
    EXPECT_EQ(*jt--, 4);
    EXPECT_EQ(*jt--, 3);
    EXPECT_EQ(*jt--, 2);
    EXPECT_EQ(*jt--, 1);
    EXPECT_EQ(*jt--, 0);
    EXPECT_EQ(*jt--, 5);
    EXPECT_EQ(*jt--, 4);
    EXPECT_EQ(*jt--, 3);
    EXPECT_EQ(*jt--, 2);
    EXPECT_EQ(*jt--, 1);
    EXPECT_EQ(*jt--, 0);
    EXPECT_EQ(*jt--, 5);
}

TEST(ListDataStructure, Ctor)
{
    List<int> a;
    EXPECT_TRUE(a.empty());
    a.push_back(1);
    a.resize(5, 100);
    a.push_back(4);
    EXPECT_TRUE(a.size() == 6);
    EXPECT_EQ(a.front(), 1);
    EXPECT_EQ(a.back(), 4);
    
    a.resize(2);
    EXPECT_EQ(a.back(), 100);

    List<int> b(a.begin(), a.end());
    EXPECT_EQ(b.front(), 1);
    EXPECT_EQ(b.back(), 100);
    b.push_back(99);
    b.push_back(98);
    b.push_back(97);

    List<int> c(b);
    std::stringstream ss;
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 100 99 98 97 }");
    
    List<int> p(5, 44); 
    ss.str("");
    ss << p;
    EXPECT_STREQ(ss.str().c_str(), "{ 44 44 44 44 44 }");
    p.push_front(11);
    p.push_back(22);
    
    List<int>::reverse_iterator it = p.rbegin();
    EXPECT_EQ(*p.begin(), 11);
    EXPECT_EQ(*it, 22);
    EXPECT_EQ(p.size(), 7);

}

TEST(List, PopPush)
{
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    std::stringstream ss;
    ss << a;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 5 }");
    
    a.pop_front();
    EXPECT_EQ(a.front(), 2);

    a.pop_back();
    EXPECT_EQ(a.back(), 4);

    a.push_front(99);
    EXPECT_EQ(a.front(), 99);

    a.push_back(98);
    EXPECT_EQ(a.back(), 98);

    a.clear();
    EXPECT_TRUE(a.empty());
}

TEST(List, insert_after)
{
    List<int> b(1);
    b.insert_after(b.begin(), 1);
    b.insert_after(b.begin(), 2);
    b.insert_after(b.begin(), 3);
    b.insert_after(b.begin(), 4);
    b.insert_after(b.begin(), 5);
    b.insert_after(b.begin(), 6);
    b.insert_after(b.begin(), 7);
    b.insert_after(b.begin(), 8);
    b.insert_after(b.begin(), 9);
    /// EXPECT_DEATH(a.insert_after(a.end(), 10), ".*");
    
    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 9 8 7 6 5 4 3 2 1 }");
    
    List<int>::iterator it = b.begin();
    ++it;
    ++it;
    ++it;
    it = b.insert_after(it, 11);   
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 9 8 7 11 6 5 4 3 2 1 }");

    b.insert_after(b.begin(), b.begin(), it); 
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 0 9 8 7 9 8 7 11 6 5 4 3 2 1 }");

    b.insert_after(it, 5, 99); 
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 0 9 8 7 9 8 7 11 99 99 99 99 99 6 5 4 3 2 1 }");

    b.insert_after(b.begin(), 3, 33); 
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 33 33 33 0 9 8 7 9 8 7 11 99 99 99 99 99 6 5 4 3 2 1 }");
}

TEST(List, insert)
{
    List<int> b;
    b.insert(b.begin(), 0);
    b.insert(b.begin(), 1);
    b.insert(b.begin(), 2);
    b.insert(b.begin(), 3);
    b.insert(b.begin(), 4);
    b.insert(b.begin(), 5);
    b.insert(b.begin(), 6);
    b.insert(b.begin(), 7);
    b.insert(b.begin(), 8);
    b.insert(b.begin(), 9);
    /// EXPECT_DEATH(b.insert(b.end()), ".*");   

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 6 5 4 3 2 1 0 }");
    
    List<int>::iterator it = b.begin();
    ++it;
    ++it;
    ++it;
    it = b.insert(it, 11);   
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 11 6 5 4 3 2 1 0 }");

    b.insert(b.begin(), b.begin(), it); 
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 9 8 7 11 6 5 4 3 2 1 0 }");

    b.insert(it, 5, 99); 
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 9 8 7 99 99 99 99 99 11 6 5 4 3 2 1 0 }");
    
    it = --b.end();
    /// it = --(--(++b.end())); /// still Segmenattion fault:)
    b.insert(it, 3, 33); 
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 9 8 7 99 99 99 99 99 11 6 5 4 3 2 1 33 33 33 0 }");
}

TEST(List, EraseEraseAfter)
{
    List<int> b;
    b.insert(b.begin(), 0);
    b.insert(b.begin(), 1);
    b.insert(b.begin(), 2);
    b.insert(b.begin(), 3);
    b.insert(b.begin(), 4);
    b.insert(b.begin(), 5);
    b.insert(b.begin(), 6);
    b.insert(b.begin(), 7);
    b.insert(b.begin(), 8);
    b.insert(b.begin(), 9);
    /// EXPECT_DEATH(b.insert(b.end()), ".*");   

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 6 5 4 3 2 1 0 }");
    
    List<int>::iterator it = b.begin();
    ++it;
    ++it;
    ++it;
    it = b.erase(it);   
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 5 4 3 2 1 0 }");

    it = b.erase_after(it);   
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 5 3 2 1 0 }");
    
    b.erase(b.begin(), it); 
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 5 3 2 1 0 }");
    /// EXPECT_DEATH(b.end(), ".*");
}

TEST(List, reverse)
{
    List<int> b;
    b.push_back(0);
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    b.push_back(5);
    b.push_back(6);
    b.push_back(7);
    b.push_back(8);
    b.push_back(9);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 1 2 3 4 5 6 7 8 9 }");
    
    b.reverse();
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 6 5 4 3 2 1 0 }");

    b.reverse();
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 1 2 3 4 5 6 7 8 9 }");
}

TEST(List, remove)
{
    List<int> b;
    b.push_back(0);
    b.push_back(2);
    b.push_back(2);
    b.push_back(2);
    b.push_back(0);
    b.push_back(2);
    b.push_back(3);
    b.push_back(5);
    b.push_back(6);
    b.push_back(6);
    b.push_back(6);
    b.push_back(0);
    b.push_back(6);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 2 2 2 0 2 3 5 6 6 6 0 6 }");
    
    b.remove(0);
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 2 2 2 2 3 5 6 6 6 6 }");
}

TEST(List, sort)
{
    List<int> b;
    b.push_back(0);
    b.push_back(2);
    b.push_back(2);
    b.push_back(2);
    b.push_back(0);
    b.push_back(2);
    b.push_back(3);
    b.push_back(5);
    b.push_back(6);
    b.push_back(6);
    b.push_back(6);
    b.push_back(0);
    b.push_back(6);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 2 2 2 0 2 3 5 6 6 6 0 6 }");
    
    b.sort();
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 0 0 2 2 2 2 3 5 6 6 6 6 }");
}

TEST(List, unique)
{
    List<int> b;
    b.push_back(0);
    b.push_back(2);
    b.push_back(2);
    b.push_back(2);
    b.push_back(0);
    b.push_back(2);
    b.push_back(3);
    b.push_back(5);
    b.push_back(6);
    b.push_back(6);
    b.push_back(6);
    b.push_back(0);
    b.push_back(6);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 2 2 2 0 2 3 5 6 6 6 0 6 }");
    
    b.unique();
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 2 0 2 3 5 6 0 6 }");
}

TEST(List, merge)
{
    List<int> b;
    b.push_back(0);
    b.push_back(2);
    b.push_back(3);
    b.push_back(5);
    b.push_back(6);

    List<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.push_back(6);
    c.push_back(7);
    c.push_back(8);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 2 3 5 6 }");
    
    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 6 7 8 }");

    b.merge(c);
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 1 2 2 3 3 5 6 6 7 8 }");
    EXPECT_TRUE(c.empty());
}

TEST(List, swap)
{
    List<int> b;
    b.push_back(0);
    b.push_back(2);
    b.push_back(3);
    b.push_back(5);
    b.push_back(6);

    List<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.push_back(6);
    c.push_back(7);
    c.push_back(8);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 2 3 5 6 }");
    
    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 6 7 8 }");

    b.swap(c);
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 6 7 8 }");

    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 2 3 5 6 }");
}

TEST(List, splice)
{
    List<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);

    List<int> c;
    c.push_back(5);
    c.push_back(6);
    c.push_back(7);
    c.push_back(8);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 }");
    
    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 5 6 7 8 }");

    b.splice(b.end(), c);
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 5 6 7 8 }");
    /*
    b.splice(++b.begin(), c);
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 5 6 7 8 2 3 4 }");
    */
    /*
    b.splice(b.begin(), c);
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 5 6 7 8 1 2 3 4 }");
    */
    EXPECT_TRUE(c.empty());
}

TEST(List, splice1)
{
    List<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);

    List<int> c;
    c.push_back(5);
    c.push_back(6);
    c.push_back(7);
    c.push_back(8);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 }");
    
    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 5 6 7 8 }");
    
    b.splice(b.end(), b, ++b.begin());
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 3 4 2 }");
    
    /*
    b.splice(b.end(), c, ++(++c.begin()));
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 7 }");
    
    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 5 6 8 }");
    */ 
    /* 
    b.splice(b.begin(), c, c.begin());
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 5 1 2 3 4 }");
    
    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 6 7 8 }");
    */
    /*
    b.splice(++b.begin(), c, ++c.begin());
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 6 2 3 4 }");
    
    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 5 7 8 }");
    */
}

TEST(List, splice2)
{
    List<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    b.push_back(5);
    b.push_back(6);

    List<int> c;
    c.push_back(7);
    c.push_back(8);
    c.push_back(9);
    c.push_back(10);
    c.push_back(11);
    c.push_back(12);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 5 6 }");
    
    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 7 8 9 10 11 12 }");
    
    b.splice(b.end(), c, c.begin(), c.end());
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 5 6 7 8 9 10 11 12 }");
    EXPECT_TRUE(c.empty()); 
    /* 
    b.splice(b.begin(), c, ++(++c.begin()), c.end());
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 10 11 12 1 2 3 4 5 6 }");
    
    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 7 8 }");
    */

    /*
    b.splice(b.end(), b, b.begin(), --(--b.end()));
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 5 6 1 2 3 4 }");
    */ 
}


int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

