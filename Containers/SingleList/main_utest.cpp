#include "headers/SingleList.hpp"
#include <gtest/gtest.h>
#include <list>
#include <sstream>
 
TEST(SingleListDataStructure, Ctor)
{
    SingleList<int> a;
    EXPECT_TRUE(a.empty());
    a.push_front(1);
    a.resize(5, 100);
    a.push_front(4);
    
    std::stringstream ss;
    ss << a;
    EXPECT_STREQ(ss.str().c_str(), "{ 4 1 100 100 100 100 }");
    EXPECT_TRUE(a.size() == 6);
    EXPECT_EQ(a.front(), 4);
    
    a.resize(2);

    SingleList<int> b(a.begin(), a.end());
    EXPECT_EQ(b.front(), 4);
    b.push_front(99);
    b.push_front(98);
    b.push_front(97);
    

    SingleList<int> c(b);
    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 97 98 99 4 1 }");
    
    SingleList<int> p(5, 44); 
    ss.str("");
    ss << p;
    EXPECT_STREQ(ss.str().c_str(), "{ 44 44 44 44 44 }");
}

TEST(SingleList, PopPush)
{
    SingleList<int> a;
    a.push_front(1);
    a.push_front(2);
    a.push_front(3);
    a.push_front(4);
    a.push_front(5);

    std::stringstream ss;
    ss << a;
    EXPECT_STREQ(ss.str().c_str(), "{ 5 4 3 2 1 }");
    
    a.pop_front();
    EXPECT_EQ(a.front(), 4);

    a.pop_front();
    EXPECT_EQ(a.front(), 3);

    a.push_front(99);
    EXPECT_EQ(a.front(), 99);

    a.push_front(98);
    
    ss.str("");
    ss << a;
    EXPECT_STREQ(ss.str().c_str(), "{ 98 99 3 2 1 }");
    
    a.clear();
    EXPECT_TRUE(a.empty());
}

TEST(SingleList, insert_after)
{
    SingleList<int> b(1);
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
    
    SingleList<int>::iterator it = b.begin();
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

TEST(SingleList, insert)
{
    SingleList<int> b;
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
    
    SingleList<int>::iterator it = b.begin();
    ++it;
    ++it;
    ++it;
    b.insert(it, 11);
    
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
    
    it = b.begin();
    SingleList<int>::iterator jt = it;
    ++jt;
    while (jt != b.end()) {
        ++it;
        ++jt;
    }
    b.insert(it, 3, 33); 
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 9 8 7 99 99 99 99 99 11 6 5 4 3 2 1 33 33 33 0 }");
}

TEST(SingleList, EraseEraseAfter)
{
    SingleList<int> b;
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
    
    SingleList<int>::iterator it = b.begin();
    ++it;
    ++it;
    ++it;
    it = b.erase(it);   
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 5 4 3 2 1 0 }");
    EXPECT_TRUE(*it == 5); 
    
    b.erase_after(it);   
    EXPECT_TRUE(*it == 5); 
    
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 5 3 2 1 0 }");
    
    b.erase(b.begin(), it);
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 5 3 2 1 0 }");
    
    b.erase(b.begin(), b.end()); 
    ss.str("");
    ss << b;
    EXPECT_TRUE(b.empty());
}

TEST(SingleList, reverse)
{
    SingleList<int> b;
    b.push_front(0);
    b.push_front(1);
    b.push_front(2);
    b.push_front(3);
    b.push_front(4);
    b.push_front(5);
    b.push_front(6);
    b.push_front(7);
    b.push_front(8);
    b.push_front(9);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 6 5 4 3 2 1 0 }");
    
    b.reverse();
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 1 2 3 4 5 6 7 8 9 }");
    
    b.reverse();
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 9 8 7 6 5 4 3 2 1 0 }");
}

TEST(SingleList, remove)
{
    SingleList<int> b;
    b.push_front(6);
    b.push_front(6);
    b.push_front(0);
    b.push_front(2);
    b.push_front(6);
    b.push_front(2);
    b.push_front(2);
    b.push_front(0);
    b.push_front(6);
    b.push_front(6);
    b.push_front(2);
    b.push_front(3);
    b.push_front(5);
    b.push_front(6);
    b.push_front(6);
    b.push_front(6);
    b.push_front(0);
    b.push_front(6);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 6 0 6 6 6 5 3 2 6 6 0 2 2 6 2 0 6 6 }");
    
    b.remove(6);
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 5 3 2 0 2 2 2 0 }");
}

TEST(SingleList, sort)
{
    SingleList<int> b;
    b.push_front(1);
    b.push_front(2);
    b.push_front(2);
    b.push_front(2);
    b.push_front(0);
    b.push_front(2);
    b.push_front(3);
    b.push_front(5);
    b.push_front(6);
    b.push_front(6);
    b.push_front(6);
    b.push_front(0);
    b.push_front(6);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 6 0 6 6 6 5 3 2 0 2 2 2 1 }");
    
    b.sort();
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 0 1 2 2 2 2 3 5 6 6 6 6 }");
}

TEST(SingleList, swap)
{
    SingleList<int> b;
    b.push_front(6);
    b.push_front(5);
    b.push_front(3);
    b.push_front(2);
    b.push_front(0);

    SingleList<int> c;
    c.push_front(8);
    c.push_front(7);
    c.push_front(6);
    c.push_front(3);
    c.push_front(2);
    c.push_front(1);

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

TEST(SingleList, unique)
{
    SingleList<int> b;
    b.push_front(1);
    b.push_front(2);
    b.push_front(2);
    b.push_front(2);
    b.push_front(0);
    b.push_front(2);
    b.push_front(3);
    b.push_front(5);
    b.push_front(6);
    b.push_front(6);
    b.push_front(6);
    b.push_front(0);
    b.push_front(6);

    std::stringstream ss;
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 6 0 6 6 6 5 3 2 0 2 2 2 1 }");
      
    b.unique();
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 6 0 6 5 3 2 0 2 1 }");

    b.sort();
    b.unique();
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 0 1 2 3 5 6 }");
    
    b.reverse();
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 6 5 3 2 1 0 }");
}

TEST(SingleList, merge)
{
    SingleList<int> b;
    b.push_front(6);
    b.push_front(5);
    b.push_front(3);
    b.push_front(2);
    b.push_front(0);

    SingleList<int> c;
    c.push_front(8);
    c.push_front(7);
    c.push_front(6);
    c.push_front(3);
    c.push_front(2);
    c.push_front(1);

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

TEST(SingleList, Ctor)
{
    SingleList<int> v;
    v.push_front(5);
    v.push_front(4);
    v.push_front(3);
    
    v.resize(5, 9);
    std::stringstream ss;
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 3 4 5 9 9 }");
    
    SingleList<int> a(v);
    ss.str("");
    ss << a;
    EXPECT_STREQ(ss.str().c_str(), "{ 3 4 5 9 9 }");
    
    SingleList<int> b;
    b = a;
    ss.str("");
    ss << b;
    EXPECT_STREQ(ss.str().c_str(), "{ 3 4 5 9 9 }");
    
    v.insert_after(v.begin(), 55);
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 3 55 4 5 9 9 }");

    v.insert(v.begin(), 44);
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 44 3 55 4 5 9 9 }");
    
    SingleList<int>::iterator it = v.begin();
    ++it;
    it++;
    ++it;
    it = v.erase(it);
    
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 44 3 55 5 9 9 }");
    EXPECT_TRUE(*it == 5);
   
    v.erase_after(v.begin()); 
    v.erase_after(it); 
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 44 55 5 9 }");
    
    v.insert_after(it, 5, 7);
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 44 55 5 7 7 7 7 7 9 }");
    
    it = v.begin();
    ++it;
    ++it;
    *it = 66;
    ++it;
    v.erase(it, v.end());
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 44 55 66 }");
    
    SingleList<int> c;
    c.push_front(1);
    c.push_front(2);
    c.push_front(3);
    c.push_front(4);

    v.swap(c);
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 4 3 2 1 }");
    
    it = v.begin();
    v.insert_after(it, c.begin(), c.end());
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 4 44 55 66 3 2 1 }");
    
    ss.str("");
    ss << c;
    EXPECT_STREQ(ss.str().c_str(), "{ 44 55 66 }");
    
    SingleList<int> t(c.begin(), c.end());
    ss.str("");
    ss << t;
    EXPECT_STREQ(ss.str().c_str(), "{ 44 55 66 }");
    t.resize(10);
    EXPECT_EQ(t.size(), 10);
    t.resize(10);
    EXPECT_EQ(t.size(), 10);
    //EXPECT_DEATH(v.insert(v.end(), 33), ".*");
}

TEST(SingleList, EraseFunctions)
{
    SingleList<int> v;
    v.push_front(9);
    v.push_front(8);
    v.push_front(7);
    v.push_front(6);
    v.push_front(5);
    v.push_front(4);
    v.push_front(3);
    v.push_front(2);
    v.push_front(1);
     
    std::stringstream ss;
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 5 6 7 8 9 }");
    SingleList<int>::iterator it = v.begin();
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    v.erase_after(it);
    assert(*it == 6);

    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 5 6 8 9 }");

    it = v.erase(it);
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 5 8 9 }");
    EXPECT_TRUE(*it == 8);

    v.erase_after(v.begin());
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 3 4 5 8 9 }");
    
    v.erase(v.begin());
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 3 4 5 8 9 }");

    ++it;
    EXPECT_TRUE(*it == 9);
    v.erase(it);
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 3 4 5 8 }");

    v.erase(v.begin(), v.end());
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ }");
    EXPECT_TRUE(v.empty());

     
}

TEST(SingleList, InsertFunctions)
{
    SingleList<int> v;
    v.push_front(9);
    v.push_front(8);
    v.push_front(7);
    v.push_front(6);
    v.push_front(5);
    v.push_front(4);
    v.push_front(3);
    v.push_front(2);
    v.push_front(1);
     
    /// insert_after()
    std::stringstream ss;
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 5 6 7 8 9 }");
    SingleList<int>::iterator it = v.begin();
    ++it;
    ++it;
    ++it;
    ++it;
    ++it;
    v.insert_after(it, 11);
    assert(*it == 6);

    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 5 6 11 7 8 9 }");

    v.insert_after(it, 22);
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 5 6 22 11 7 8 9 }");

    v.insert_after(v.begin(), v.begin(), v.end());
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 1 2 3 4 5 6 22 11 7 8 9 2 3 4 5 6 22 11 7 8 9 }");

    v.insert_after(v.begin());
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 0 1 2 3 4 5 6 22 11 7 8 9 2 3 4 5 6 22 11 7 8 9 }");

    it = v.begin();
    v.insert_after(v.begin(), 4, 99); 
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 99 99 99 99 0 1 2 3 4 5 6 22 11 7 8 9 2 3 4 5 6 22 11 7 8 9 }");
    
    /// insert()
    v.erase(v.begin(), v.end());
    EXPECT_TRUE(v.empty());

    v.push_front(3);
    v.push_front(2);
    v.push_front(1);
    it = v.begin();
    ++it;
    v.insert(it, 11);
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 11 2 3 }");
    
    ++it;
    ++it;
    v.insert(it, 22);
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 11 2 22 3 }");

    v.insert(v.begin(), 5, 99); 
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 99 99 99 99 99 1 11 2 22 3 }");

    v.insert(v.begin(), v.begin(), v.end());
    ss.str("");
    ss << v;
    EXPECT_STREQ(ss.str().c_str(), "{ 99 99 99 99 99 1 11 2 22 3 99 99 99 99 99 1 11 2 22 3 }");
}

TEST(SingleList, functions)
{
    SingleList<int> v;
    v.push_front(5);
    v.push_front(4);
    v.push_front(3);
    v.resize(5, 9);
     
    std::stringstream ss;
    ss << v;
    EXPECT_EQ(ss.str(), "{ 3 4 5 9 9 }");
    EXPECT_EQ(v.front(), 3); 
    v.pop_front();
    EXPECT_EQ(v.front(), 4);
    
    v.resize(1);
    ss.str("");
    ss << v;
    EXPECT_EQ(ss.str(), "{ 4 }");
    EXPECT_EQ(v.size(), 1);
                                 
    SingleList<int> a(v);
    EXPECT_TRUE(a == v);
    
    SingleList<int> b = a;
    SingleList<int>::iterator it = b.begin();
    *it = 7;
    EXPECT_TRUE(b > v);

    SingleList<int> c;
    c.push_front(3);
    c.pop_front();
    EXPECT_TRUE(c.empty());
}

TEST(SingleList, splice1)
{
    SingleList<int> a;
    a.push_front(5);
    a.push_front(4);
    a.push_front(3);
    a.push_front(2);
    a.push_front(1);
    
    SingleList<int> b;
    b.push_front(10);
    b.push_front(9);
    b.push_front(8);
    b.push_front(7);
    b.push_front(6);
     
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 7 8 9 10 }");
    
    a.splice(++a.begin(), b);
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 6 7 8 9 10 2 3 4 5 }");
    EXPECT_TRUE(b.empty());
    /*
    a.splice(a.end(), b);
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 6 7 8 9 10 }");
    EXPECT_TRUE(b.empty());
    */
    /*
    a.splice(a.begin(), b);
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 6 7 8 9 10 1 2 3 4 5 }");
    EXPECT_TRUE(b.empty());
    */
}

TEST(SingleList, splice2)
{
    SingleList<int> a;
    a.push_front(5);
    a.push_front(4);
    a.push_front(3);
    a.push_front(2);
    a.push_front(1);
    
    SingleList<int> b;
    b.push_front(10);
    b.push_front(9);
    b.push_front(8);
    b.push_front(7);
    b.push_front(6);
     
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 7 8 9 10 }");
    
    /*
    a.splice(++a.begin(), b, b.begin());
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 6 2 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 7 8 9 10 }");
    */
    
    /*
    a.splice(a.end(), b, ++b.begin());
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 7 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 8 9 10 }");
    */
    /*
    a.splice(a.begin(), b, ++(++b.begin()));
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 8 1 2 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 7 9 10 }");
    */
    a.splice(a.begin(), a, ++(++a.begin()));
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 3 1 2 4 5 }");
}

TEST(SingleList, splice3)
{
    SingleList<int> a;
    a.push_front(5);
    a.push_front(4);
    a.push_front(3);
    a.push_front(2);
    a.push_front(1);
    
    SingleList<int> b;
    b.push_front(10);
    b.push_front(9);
    b.push_front(8);
    b.push_front(7);
    b.push_front(6);
     
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 7 8 9 10 }");
    
    /*
    a.splice(++a.begin(), b, b.begin(), ++(++b.begin()));
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 6 7 2 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 8 9 10 }");
    
    */
    /*
    a.splice(a.end(), b, ++b.begin(), b.end());
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 7 8 9 10 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 }");
    */
    /*
    a.splice(a.begin(), b, ++(++b.begin()), b.end());
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 8 9 10 1 2 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 7 }");
    */
    
    a.splice(a.begin(), a, ++(++a.begin()), a.end());
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 3 4 5 1 2 }");
}

TEST(SingleList, splice4)
{
    SingleList<int> a;
    a.push_front(5);
    a.push_front(4);
    a.push_front(3);
    a.push_front(2);
    a.push_front(1);
    
    SingleList<int> b;
    b.push_front(10);
    b.push_front(9);
    b.push_front(8);
    b.push_front(7);
    b.push_front(6);
     
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 7 8 9 10 }");
    
    /*
    a.splice_after(a.begin(), b.begin());
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 7 2 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 8 9 10 }");
    */
    
    /*
    a.splice_after(++a.begin(), ++b.begin());
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 8 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 7 9 10 }");
    */
    a.splice_after(a.begin(), ++(++(++a.begin())));
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 5 2 3 4 }");
}

TEST(SingleList, splice5)
{
    SingleList<int> a;
    a.push_front(5);
    a.push_front(4);
    a.push_front(3);
    a.push_front(2);
    a.push_front(1);
    
    SingleList<int> b;
    b.push_front(10);
    b.push_front(9);
    b.push_front(8);
    b.push_front(7);
    b.push_front(6);
     
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 7 8 9 10 }");
    
    /*
    a.splice_after(a.begin(), b.begin(), ++(++b.begin()));
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 7 8 2 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 9 10 }");
    */
    
    /*
    a.splice_after(++a.begin(), ++b.begin(), ++(++(++(b.begin()))));
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 8 9 3 4 5 }");
    
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 6 7 10 }");
    */
    a.splice_after(a.begin(), a.begin(), ++(++(++a.begin())));
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 5 }");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

