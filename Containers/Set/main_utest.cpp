#include "headers/Set.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(a, b)
{
    Set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(9);
    
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "1 2 5 9 \n");
}
  
TEST(Setint, insert)
{
    Set<int> s;
    s.insert(100);
    s.insert(50);
    s.insert(150);
    s.insert(20);
    s.insert(70);
    s.insert(120);
    s.insert(170);
    s.insert(10);
    s.insert(30);
    s.insert(60);
    s.insert(80);
    s.insert(110);
    s.insert(130);
    s.insert(160);
    s.insert(180);
    
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "10 20 30 50 60 70 80 100 110 120 130 150 160 170 180 \n"); 
    
    //std::cout << s << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
     
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    std::cout << (s.empty() ? "empty" : "Not") << std::endl;
    s.print(); 
       
    const int size = 9;
    int arr[size] = {11, 22, 33, 44, 55, 66, 77, 88, 99}; 
    s.insert(arr, arr + size);
    std::cout << s << std::endl;
}

TEST(SetInt, CopyConstructor)
{
    Set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    
    Set<int> b = s;
    EXPECT_TRUE(b == s);
    
    Set<int> c;
    c = b;
    EXPECT_TRUE(c == s);

    std::stringstream ss1;
    c.print(ss1);
    std::stringstream ss2;
    s.print(ss2);
    EXPECT_EQ(ss1.str(), ss2.str()); 
}
  
TEST(SetInt, RangeConstructor)
{
    const int size = 6;
    int arr[size] = {4, 1, 1, 4, 5, 6};
    Set<int> s(arr, arr + size);
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "1 4 5 6 \n");

}

TEST(SetInt, EraseIterator1)
{
    Set<int> s;
    s.insert(4);
    s.insert(1);
    s.insert(6);
    s.erase(s.begin());
    std::cout << s << std::endl;
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "4 6 \n");
}

TEST(SetInt, EraseIterator2)
{
    Set<int> s;
    s.insert(4);
    s.insert(1);
    s.insert(6);
    s.erase(++s.begin());
    std::cout << s << std::endl;
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "1 6 \n");
}

TEST(SetInt, EraseIterator3)
{
    Set<int> s;
    s.insert(4);
    std::cout << s << std::endl;
    s.insert(1);
    std::cout << s << std::endl;
    s.insert(3);
    std::cout << s << std::endl;
    s.erase(++(++s.begin()));
    std::cout << s << std::endl;
    s.erase(++s.begin());
    std::cout << s << std::endl;
    s.erase(s.begin());
    std::cout << s << std::endl;
    std::stringstream ss;
    s.print(ss);
    EXPECT_EQ(ss.str(), "\n");
}

TEST(SetInt, RangeErase)
{
    Set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(1);
    
    std::cout << s << std::endl;
    
    s.erase(++(s.begin()));
    std::cout << s << "\n\n" << std::endl;
    
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    
    s.erase(s.begin());
    std::cout << s << "\n\n" << std::endl;
    EXPECT_TRUE(s.empty());
    
    Set<int>::iterator it = s.begin();
    Set<int>::iterator jt = s.end();
    s.erase(it, jt);
    s.print();
}

TEST(SetInt, Big_RangeErase)
{
    Set<int> s;
    s.insert(4);
    s.insert(1);
    s.insert(6);
    s.insert(32);
    s.insert(13);
    s.insert(10);
    s.insert(11);
    s.insert(30);
    std::cout << s << std::endl;
    Set<int>::iterator it = s.begin();
    Set<int>::iterator jt = s.end();
    s.erase(it, jt);
    s.print();
    EXPECT_TRUE(s.empty());
}

TEST(SetInt, RangeErase1)
{
    int arr[] = {4, 1, 9, 2, 7, 6};
    Set<int> s(arr, arr + 6);
    Set<int>::iterator it = s.begin();
    Set<int>::iterator jt = s.end();
    EXPECT_EQ(*it, 1);
    std::cout << s << std::endl;
    s.erase(it, jt);
    EXPECT_TRUE(s.empty());
}

TEST(SetInt, eraseKey)
{
    int arr[] = {4, 1, 9, 2, 7, 6};
    Set<int> s(arr, arr + 6);
    std::cout << s << std::endl;
    s.erase(1);
    std::cout << s << std::endl;
    s.erase(4);
    std::cout << s << std::endl;
    s.erase(9);
    std::cout << s << std::endl;
    s.erase(2);
    std::cout << s << std::endl;
    s.erase(7);
    std::cout << s << std::endl;
    s.erase(6);
    std::cout << s << std::endl;
    EXPECT_TRUE(s.empty());
}

TEST(SetInt, erase42)
{
    Set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(15);
    s.insert(12);
    s.insert(18);
    s.insert(0);
    s.insert(11);
    s.insert(13);
    s.insert(16);
    s.insert(19);
    std::cout << s << "\n\n" << std::endl;
    
}

TEST(SetInt, decrement)
{
    Set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(15);
    s.insert(12);
    s.insert(18);
    s.insert(0);
    s.insert(11);
    s.insert(13);
    s.insert(16);
    s.insert(19);
    std::cout << s << "\n\n" << std::endl;
    Set<int>::const_iterator first = s.begin();
    while (first != s.end()) {
        std::cout << *(first) << ' ';
        ++first;
    }    
    std::cout << std::endl;
    Set<int>::const_iterator last = s.find(19); 
    while (last != s.end()) {
        std::cout << *last-- << ' ';
    }    
    std::cout << std::endl;
    Set<int>::reverse_iterator b = s.rbegin();
    while (b != s.rend()) { std::cout << *b << ' '; ++b; }
    b = s.rbegin();
    std::cout << *(b.operator->()) << std::endl;    
}

TEST(SetInt, bounds)
{
    Set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(15);
    s.insert(12);
    s.insert(18);
    s.insert(0);
    s.insert(11);
    s.insert(13);
    s.insert(16);
    s.insert(19);
    std::cout << s << "\n\n" << std::endl;
    int key1 = 4;
    EXPECT_TRUE(*s.lower_bound(key1) == 11);
    EXPECT_TRUE(*s.upper_bound(key1) == 11);
    int key2 = 16;
    EXPECT_TRUE(*s.lower_bound(key2) == 16);
    EXPECT_TRUE(*s.upper_bound(key2) == 18);
}

TEST(SetInt, eraseKey4)
{
    Set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(2);
    s.insert(8);
    s.insert(12);
    s.insert(18);
    s.insert(0);
    s.insert(3);
    s.insert(6);
    s.insert(9);
    s.insert(11);
    s.insert(13);
    s.insert(16);
    s.insert(19);
    std::cout << s << "\n\n" << std::endl;
    
    s.erase(5);
    std::cout << s << "\n\n" << std::endl;
    
    s.erase(10);
    std::cout << s << "\n\n" << std::endl;
    s.erase(9);
    std::cout << s << "\n\n" << std::endl;
    s.erase(8);
    std::cout << s << "\n\n" << std::endl;
    s.erase(6);
    std::cout << s << "\n\n" << std::endl;
    s.erase(3);
    std::cout << s << "\n\n" << std::endl;
    s.erase(0);
    std::cout << s << "\n\n" << std::endl;
    s.erase(2);
    std::cout << s << "\n\n" << std::endl;
    
    std::stringstream ss1, ss2;
    s.preOrderIter(ss1);
    s.preOrderRec(ss2);
    EXPECT_TRUE(ss1.str() == ss2.str()); 
    
    ss1.str("");
    ss2.str("");
    s.inOrderIter(ss1);
    s.inOrderRec(ss2);
    EXPECT_TRUE(ss1.str() == ss2.str()); 
    
    ss1.str("");
    ss2.str("");
    s.postOrderRec(ss2);
    EXPECT_EQ(ss2.str(), "11 13 12 16 19 18 15 ");
    s.postOrderIter(ss1);
    EXPECT_EQ(ss1.str(), "11 13 12 16 19 18 15 ");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

