#include "headers/Vector.hpp"
#include "headers/CustomClass.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(IntVectorTest, CtorTests)
{
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
   
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 6 7 }"); 

    Vector<int> b(5, 99);
    ss.str("");
    ss << b;
    EXPECT_EQ(ss.str(), "{ 99 99 99 99 99 }"); 

    Vector<int> d(5);
    ss.str("");
    ss << d;
    EXPECT_EQ(ss.str(), "{ 0 0 0 0 0 }"); 

    Vector<int> c(a.begin(), a.begin() + 5);
    ss.str("");
    ss << c;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 }"); 
}

TEST(IntVectorTest, insert)
{
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
   
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 6 7 }"); 

    a.insert(a.begin(), 8);
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 8 1 2 3 4 5 6 7 }"); 

    a.insert(a.end(), 9);
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 8 1 2 3 4 5 6 7 9 }"); 

    a.insert(a.end() - 3, 10);
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 8 1 2 3 4 5 10 6 7 9 }"); 

    a.insert(a.begin(), 3, 11);
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 11 11 11 8 1 2 3 4 5 10 6 7 9 }"); 

    Vector<int> b = a;
    a.insert(a.begin(), b.begin() + 4, b.begin() + 9);
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 1 2 3 4 5 11 11 11 8 1 2 3 4 5 10 6 7 9 }"); 
}

TEST(IntVectorTest, erase)
{
    Vector<int> a(1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    a.push_back(10);
    a.push_back(11);
    a.push_back(12);
 
    std::stringstream ss;
    ss << a;
    EXPECT_EQ(ss.str(), "{ 0 1 2 3 4 5 6 7 8 9 10 11 12 }");   

    a.erase(a.begin() + 5);
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 0 1 2 3 4 6 7 8 9 10 11 12 }");   

    a.erase(a.begin() + 2, a.end() - 6);
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 0 1 7 8 9 10 11 12 }");   

    a.erase(a.begin(), a.end() - 3);
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ 10 11 12 }");   

    a.erase(a.begin(), a.end());
    ss.str("");
    ss << a;
    EXPECT_EQ(ss.str(), "{ }");   
}

TEST(IntVectorTest, ConstIteratorTests)
{
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    
    Vector<int>::const_iterator it = a.begin();
    EXPECT_TRUE(*it == 1); 
    
    it++;
    EXPECT_TRUE(*it == 2); 
    
    ++it;
    EXPECT_TRUE(*it == 3); 
    
    it += 4;
    EXPECT_TRUE(*it == 7); 
    
    EXPECT_TRUE(it == a.end() - 1); 

    it -= (a.size() - 1);
    EXPECT_TRUE(it == a.begin());

    it += 2;
    --it;
    EXPECT_EQ(*it, 2);
    
    it--;
    EXPECT_EQ(*it, 1);
    EXPECT_EQ(it[6], 7);
    EXPECT_TRUE(a.begin() < a.end() - 1);

    std::stringstream ss;
    ss << a;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 5 6 7 }");
}

TEST(IntVectorTest, IteratorTests)
{
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);

    Vector<int>::iterator it = a.begin();
    EXPECT_TRUE(*it == 1); 
    
    Vector<int>::iterator it1 = it++;
    EXPECT_TRUE(*it == 2); 
    EXPECT_TRUE(*it1 == 1); 
                                    
    it1 = ++it;
    EXPECT_TRUE(*it == 3); 
    EXPECT_TRUE(*it1 == 3); 
    
    it += 4;
    EXPECT_TRUE(*it == 7); 
    
    EXPECT_TRUE(it == a.end() - 1); 

    it -= (a.size() - 1);
    EXPECT_TRUE(it == a.begin());

    it += 2;
    --it;
    EXPECT_EQ(*it, 2);
    
    it--;
    EXPECT_EQ(*it, 1);
    EXPECT_EQ(it[6], 7);
    EXPECT_TRUE(a.begin() < a.end() - 1);

    it = a.end() - 1;
    *it = 99;
    EXPECT_TRUE(*(a.end() - 1) == 99);
}

TEST(IntVectorTest, ConstReverseIteratorTests)
{
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);

    Vector<int>::const_reverse_iterator it = a.rbegin();
    EXPECT_TRUE(*it == 7);

    Vector<int>::const_reverse_iterator it1 = ++it;
    EXPECT_TRUE(*it == 6);
    EXPECT_TRUE(*it1 == 6);

    it1 = it++;
    EXPECT_TRUE(*it == 5);
    EXPECT_TRUE(*it1 == 6);
    
    it += 4;
    EXPECT_TRUE(*it == 1);
    
    it -= 2;
    EXPECT_TRUE(*it == 3);
    
    EXPECT_EQ(*(a.rend() - 1), 1); 
    EXPECT_EQ(*(a.rend() - 2), 2); 
}

TEST(IntVectorTest, DefaultConstructorSize)
{
    Vector<int> v;
    EXPECT_TRUE(v.empty());
    
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);

    v.push_back(11);
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.capacity(), 1);

    v.push_back(22);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.capacity(), 2);

    v.push_back(33);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 4);

    v.push_back(44);
    EXPECT_EQ(v.size(), 4);
    EXPECT_EQ(v.capacity(), 4);

    v.push_back(55);
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 8);

    v.pop_back();
    EXPECT_EQ(v.size(), 4);
    EXPECT_EQ(v.capacity(), 8);

    v.pop_back();
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 8);

    EXPECT_EQ(v.front(), 11);
    EXPECT_EQ(v.back(), 33);

    v.clear();
    EXPECT_TRUE(v == Vector<int>());
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
    
    v.reserve(8);
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 8);

    v.reserve(12);
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 12);

    v.resize(15);
    EXPECT_EQ(v.size(), 15);
    EXPECT_EQ(v.capacity(), 15);
    for (Vector<int>::size_type i = 0; i < v.size(); ++i) {
        EXPECT_EQ(v[i], int());
    }
}

TEST(IntVectorTest, OneParameterConstructor)
{
    Vector<int> v(5);
    EXPECT_FALSE(v.empty());
    
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 5);

    v.push_back(11);
    EXPECT_TRUE(v[5] == 11);
    EXPECT_EQ(v.size(), 6);
    EXPECT_EQ(v.capacity(), 10);
    
    v.push_back(22);
    EXPECT_TRUE(v[6] == 22);
    EXPECT_EQ(v.size(), 7);
    EXPECT_EQ(v.capacity(), 10);

    v.push_back(33);
    EXPECT_TRUE(v[v.size() - 1]== 33);
    EXPECT_EQ(v.size(), 8);
    EXPECT_EQ(v.capacity(), 10);

    v.push_back(44);
    EXPECT_TRUE(v[v.size() - 1] == 44);
    EXPECT_EQ(v.size(), 9);
    EXPECT_EQ(v.capacity(), 10);

    v.push_back(55);
    EXPECT_TRUE(v[v.size() - 1] == 55);
    EXPECT_EQ(v.size(), 10);
    EXPECT_EQ(v.capacity(), 10);

    v.push_back(66);
    EXPECT_TRUE(v[v.size() - 1] == 66);
    EXPECT_EQ(v.size(), 11);
    EXPECT_EQ(v.capacity(), 20);
    
    v.pop_back();
    EXPECT_TRUE(v[v.size() - 1] == 55);
    EXPECT_EQ(v.size(), 10);
    EXPECT_EQ(v.capacity(), 20);

    v.pop_back();
    EXPECT_TRUE(v[v.size() - 1] == 44);
    EXPECT_EQ(v.size(), 9);
    EXPECT_EQ(v.capacity(), 20);
    
    EXPECT_EQ(v.front(), 0);
    EXPECT_EQ(v.back(), 44);

    Vector<int> copy;
    copy = v;
    EXPECT_TRUE(copy == v);
}

TEST(IntVectorTest, TwoParameterConstructor)
{
    Vector<int> v(9, 99);
    EXPECT_FALSE(v.empty());
    Vector<int>::size_type size = v.size();
    for (Vector<int>::size_type i = 0; i < size; ++i) {
        EXPECT_EQ(v[i], 99);
    }
    EXPECT_EQ(v.size(), 9);
    EXPECT_EQ(v.capacity(), 9);
    
    v.push_back(11);
    EXPECT_EQ(v.size(), 10);
    EXPECT_EQ(v.capacity(), 18);
    EXPECT_TRUE(v[v.size() - 1] == 11);

    v.pop_back();
    EXPECT_TRUE(v[v.size() - 1] == 99);

    Vector<int> copy = v;
    EXPECT_TRUE(copy == v);
}

TEST(IntVectorTest, RelationalOperators)
{
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(5);
    
    Vector<int> v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
    EXPECT_TRUE(v1 > v2);
    
    Vector<int> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(4);
    v3.push_back(5);
    
    Vector<int> v4;
    v4.push_back(1);
    v4.push_back(3);
    v4.push_back(3);
    v4.push_back(5);
    EXPECT_TRUE(v3 < v4);
}

TEST(IntVectorTest, RangeCtor)
{
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(5);
    
    Vector<int> v2(v1.begin(), v1.end());
    EXPECT_TRUE(v1 == v2);
}

TEST(IntVectorTest, InsertionAndDeletion)
{
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    EXPECT_TRUE(v1.size() == 5);
    std::stringstream ss1;
    ss1 << v1;
    EXPECT_STREQ(ss1.str().c_str(), "{ 1 2 3 4 5 }");
    
    ss1.str("");
    v1.insert(v1.begin(), 11);
    ss1 << v1; 
    EXPECT_STREQ(ss1.str().c_str(), "{ 11 1 2 3 4 5 }");
    EXPECT_TRUE(v1.size() == 6);
    
    ss1.str("");
    v1.insert(v1.begin() + 2, 22);
    ss1 << v1; 
    EXPECT_STREQ(ss1.str().c_str(), "{ 11 1 22 2 3 4 5 }");
    EXPECT_TRUE(v1.size() == 7);
    
    ss1.str("");
    v1.insert(v1.end(), 33);
    ss1 << v1; 
    EXPECT_STREQ(ss1.str().c_str(), "{ 11 1 22 2 3 4 5 33 }");
    EXPECT_TRUE(v1.size() == 8);
    
    ss1.str("");
    v1.erase(v1.end() - 1);
    ss1 << v1; 
    EXPECT_STREQ(ss1.str().c_str(), "{ 11 1 22 2 3 4 5 }");
    EXPECT_TRUE(v1.size() == 7);
    
    ss1.str("");
    v1.erase(v1.begin() + 5);
    ss1 << v1; 
    EXPECT_STREQ(ss1.str().c_str(), "{ 11 1 22 2 3 5 }");
    EXPECT_TRUE(v1.size() == 6);
    
    ss1.str("");
    v1.erase(v1.begin());
    ss1 << v1; 
    EXPECT_STREQ(ss1.str().c_str(), "{ 1 22 2 3 5 }");
    EXPECT_TRUE(v1.size() == 5);

    Vector<int> v2;
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    v2.push_back(9);
    v2.push_back(10);
    
    std::stringstream ss2;
    ss2 << v2;
    EXPECT_STREQ(ss2.str().c_str(), "{ 6 7 8 9 10 }");
    EXPECT_TRUE(v2.size() == 5);
    
    ss2.str(""); 
    v2.insert(v2.begin() + 3, 5, 11);
    ss2 << v2;
    EXPECT_STREQ(ss2.str().c_str(), "{ 6 7 8 11 11 11 11 11 9 10 }");
    EXPECT_TRUE(v2.size() == 10);
    
    ss2.str(""); 
    v2.insert(v2.begin(), v1.begin(), v1.begin() + 5);
    ss2 << v2;
    EXPECT_STREQ(ss2.str().c_str(), "{ 1 22 2 3 5 6 7 8 11 11 11 11 11 9 10 }");
    EXPECT_TRUE(v2.size() == 15);

    ss2.str(""); 
    v2.erase(v2.begin() + 3, v2.begin() + 9);
    ss2 << v2;
    EXPECT_STREQ(ss2.str().c_str(), "{ 1 22 2 11 11 11 11 9 10 }");
    EXPECT_TRUE(v2.size() == 9);

    ss2.str(""); 
    v2.erase(v2.begin(), v2.end());
    ss2 << v2;
    EXPECT_STREQ(ss2.str().c_str(), "{ }");
    EXPECT_TRUE(v2.size() == 0);
}

TEST(CustomVectorTest, DefaultConstructorSize)
{
    Vector<CustomClass> v;
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);

    v.push_back(11);
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.capacity(), 1);

    v.push_back(22);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.capacity(), 2);

    v.push_back(33);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 4);

    v.push_back(44);
    EXPECT_EQ(v.size(), 4);
    EXPECT_EQ(v.capacity(), 4);

    v.push_back(55);
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 8);

    v.pop_back();
    EXPECT_EQ(v.size(), 4);
    EXPECT_EQ(v.capacity(), 8);

    v.pop_back();
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 8);

    EXPECT_EQ(v.front(), 11);
    EXPECT_EQ(v.back(), 33);

    v.clear();
    EXPECT_TRUE(v == Vector<CustomClass>());
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
    
    v.reserve(8);
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 8);

    v.reserve(12);
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 12);

    v.resize(15);
    EXPECT_EQ(v.size(), 15);
    EXPECT_EQ(v.capacity(), 15);
    for (Vector<CustomClass>::size_type i = 0; i < v.size(); ++i) {
        EXPECT_EQ(v[i], CustomClass());
    }
    
}

TEST(CustomVectorTest, OneParameterConstructor)
{
    Vector<CustomClass> v(5);
    EXPECT_FALSE(v.empty());
    
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 5);

    v.push_back(11);
    EXPECT_TRUE(v[5] == 11);
    EXPECT_EQ(v.size(), 6);
    EXPECT_EQ(v.capacity(), 10);

    v.push_back(22);
    EXPECT_TRUE(v[6] == 22);
    EXPECT_EQ(v.size(), 7);
    EXPECT_EQ(v.capacity(), 10);

    v.push_back(33);
    EXPECT_TRUE(v[v.size() - 1]== 33);
    EXPECT_EQ(v.size(), 8);
    EXPECT_EQ(v.capacity(), 10);

    v.push_back(44);
    EXPECT_TRUE(v[v.size() - 1] == 44);
    EXPECT_EQ(v.size(), 9);
    EXPECT_EQ(v.capacity(), 10);

    v.push_back(55);
    EXPECT_TRUE(v[v.size() - 1] == 55);
    EXPECT_EQ(v.size(), 10);
    EXPECT_EQ(v.capacity(), 10);

    v.push_back(66);
    EXPECT_TRUE(v[v.size() - 1] == 66);
    EXPECT_EQ(v.size(), 11);
    EXPECT_EQ(v.capacity(), 20);
    
    v.pop_back();
    EXPECT_TRUE(v[v.size() - 1] == 55);
    EXPECT_EQ(v.size(), 10);
    EXPECT_EQ(v.capacity(), 20);

    v.pop_back();
    EXPECT_TRUE(v[v.size() - 1] == 44);
    EXPECT_EQ(v.size(), 9);
    EXPECT_EQ(v.capacity(), 20);
    
    EXPECT_EQ(v.front(), 0);
    EXPECT_EQ(v.back(), 44);

    Vector<CustomClass> copy;
    copy = v;
    EXPECT_TRUE(copy == v);
}

TEST(CustomVectorTest, TwoParameterConstructor)
{
    Vector<CustomClass> v(9, CustomClass(99));
    EXPECT_FALSE(v.empty());
    Vector<CustomClass>::size_type size = v.size();
    for (Vector<CustomClass>::size_type i = 0; i < size; ++i) {
        EXPECT_EQ(v[i], 99);
    }
    EXPECT_EQ(v.size(), 9);
    EXPECT_EQ(v.capacity(), 9);
    
    v.push_back(11);
    EXPECT_EQ(v.size(), 10);
    EXPECT_EQ(v.capacity(), 18);
    EXPECT_TRUE(v[v.size() - 1] == 11);

    v.pop_back();
    EXPECT_TRUE(v[v.size() - 1] == 99);

    Vector<CustomClass> copy = v;
    EXPECT_TRUE(copy == v);
}

TEST(CustomVectorTest, RelationalOperators)
{
    Vector<CustomClass> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(5);
    
    Vector<CustomClass> v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
    EXPECT_TRUE(v1 > v2);
    
    Vector<CustomClass> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(4);
    v3.push_back(5);
    
    Vector<CustomClass> v4;
    v4.push_back(1);
    v4.push_back(3);
    v4.push_back(3);
    v4.push_back(5);
    EXPECT_TRUE(v3 < v4);
}

TEST(IntVectorTest, 2DVectors)
{
    Vector<Vector<int> > v1(5, Vector<int>(3, 4));
    v1.push_back(Vector<int>(5, 6)); 
    v1.push_back(Vector<int>(7, 2)); 
    for (Vector<Vector<int> >::const_iterator it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << v1.size() << std::endl;
    for (Vector<int>::size_type i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << std::endl;
    }
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

