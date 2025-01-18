#include "headers/functions.hpp"
#include "headers/Functors.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <cmath>

TEST(myAlgorithms, count_if)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_back(8);
    
    EXPECT_TRUE(std::count_if(lst.begin(), lst.end(), my::IsEven()) == my::count_if(lst.begin(), lst.end(), my::IsEven()));
    
    int m = 0;
    my::count_if(lst.begin(), lst.end(), my::IsEven(), m);
    EXPECT_TRUE(4 == m);
}

TEST(a, b1)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    
    
    EXPECT_TRUE(std::mismatch(lst.begin(), lst.end(), vec.begin()) == 
                 my::mismatch(lst.begin(), lst.end(), vec.begin()));
}

TEST(a, c1)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    
    
    EXPECT_TRUE(std::mismatch(lst.begin(), lst.end(), vec.begin()) == 
                 my::mismatch(lst.begin(), lst.end(), vec.begin()));
}

TEST(a, d1)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    
    
    EXPECT_TRUE(std::equal(lst.begin(), lst.end(), vec.begin()) == 
                 my::equal(lst.begin(), lst.end(), vec.begin()));
}

TEST(a, e1)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    
    
    EXPECT_TRUE(std::equal(lst.begin(), lst.end(), vec.begin()) == 
                 my::equal(lst.begin(), lst.end(), vec.begin()));
}

TEST(a, c2)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_back(8);
    
    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    
    std::cout << *std::search(lst.begin(), lst.end(), vec.begin(), vec.end()) << std::endl; 
    std::cout <<  *my::search(lst.begin(), lst.end(), vec.begin(), vec.end()) << std::endl; 
    EXPECT_TRUE(std::search(lst.begin(), lst.end(), vec.begin(), vec.end()) == 
                 my::search(lst.begin(), lst.end(), vec.begin(), vec.end()));
}

TEST(a, c3)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    
    std::cout << *std::search(lst.begin(), lst.end(), vec.begin(), vec.end(), my::IsEqual()) << std::endl; 
    std::cout <<  *my::search(lst.begin(), lst.end(), vec.begin(), vec.end(), my::IsEqual()) << std::endl; 
    EXPECT_TRUE(std::search(lst.begin(), lst.end(), vec.begin(), vec.end(), my::IsEqual()) == 
                 my::search(lst.begin(), lst.end(), vec.begin(), vec.end(), my::IsEqual()));
}

TEST(a, d2)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(4);
    lst.push_back(4);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    
    
    std::cout << *std::search_n(lst.begin(), lst.end(), 3, 4) << std::endl; 
    std::cout <<  *my::search_n(lst.begin(), lst.end(), 3, 4) << std::endl; 
    EXPECT_TRUE(std::search_n(lst.begin(), lst.end(), 3, 4) == 
                 my::search_n(lst.begin(), lst.end(), 3, 4));
    
    std::cout << *std::search_n(vec.begin(), vec.end(), 3, 4) << std::endl; 
    std::cout <<  *my::search_n(vec.begin(), vec.end(), 3, 4) << std::endl; 
    EXPECT_TRUE(std::search_n(vec.begin(), vec.end(), 3, 4) == 
                 my::search_n(vec.begin(), vec.end(), 3, 4));
}

TEST(a, e2)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_back(8);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_back(8);
    lst.push_back(8);
    lst.push_back(7);
    lst.push_back(8);
    
    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    
    std::cout << *std::find_end(lst.begin(), lst.end(), vec.begin(), vec.end()) << std::endl; 
    std::cout <<  *my::find_end(lst.begin(), lst.end(), vec.begin(), vec.end()) << std::endl; 
    EXPECT_TRUE(std::find_end(lst.begin(), lst.end(), vec.begin(), vec.end()) == 
                 my::find_end(lst.begin(), lst.end(), vec.begin(), vec.end()));
}

TEST(a, f2)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    
    std::cout << *std::find_end(lst.begin(), lst.end(), vec.begin(), vec.end(), my::IsEqual()) << std::endl; 
    std::cout <<  *my::find_end(lst.begin(), lst.end(), vec.begin(), vec.end(), my::IsEqual()) << std::endl; 
    EXPECT_TRUE(std::find_end(lst.begin(), lst.end(), vec.begin(), vec.end(), my::IsEqual()) == 
                 my::find_end(lst.begin(), lst.end(), vec.begin(), vec.end(), my::IsEqual()));
}


TEST(a, b4)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_back(8);
    
    std::vector<int> vec1(lst.size());
    std::vector<int> vec2(lst.size());
    std::transform(lst.begin(), lst.end(), vec1.begin(), my::UnaryFunction());
    my::transform(lst.begin(), lst.end(), vec2.begin(), my::UnaryFunction());
    EXPECT_TRUE(vec1 == vec2);
    
}

TEST(a, c4)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    
    std::vector<int> vec1(lst.size());
    std::vector<int> vec2(lst.size());
    std::transform(lst.begin(), lst.end(), vec.begin(), vec1.begin(), my::BinaryFunction());
    my::transform(lst.begin(), lst.end(), vec.begin(), vec2.begin(), my::BinaryFunction());
    EXPECT_TRUE(vec1 == vec2);
}

TEST(a, d4)
{
    std::list<int> lst1;
    lst1.push_back(1);
    lst1.push_back(2);
    lst1.push_back(3);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(5);
    lst1.push_back(6);
    
    std::list<int> lst2;
    lst2.push_back(1);
    lst2.push_back(2);
    lst2.push_back(3);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(5);
    lst2.push_back(6);
    
    
    std::replace_if(lst1.begin(), lst1.end(), my::IsEven(), 99);
    my::replace_if(lst2.begin(), lst2.end(), my::IsEven(), 99);
    EXPECT_TRUE(lst1 == lst2); 
}

TEST(a, e4)
{
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_back(8);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_back(8);
    lst.push_back(8);
    lst.push_back(7);
    lst.push_back(8);
    
    std::vector<int> vec1(lst.size());
    std::vector<int> vec2(lst.size());
    std::replace_copy_if(lst.begin(), lst.end(), vec1.begin(), my::IsEven(), 88);
    my::replace_copy_if(lst.begin(), lst.end(), vec2.begin(), my::IsEven(), 88);
    EXPECT_TRUE(vec1 == vec2);
}


TEST(a, b5)
{
    const int SIZE = 10;
    std::list<int> lst1(SIZE);
    std::list<int> lst2(SIZE);
    std::generate(lst1.begin(), lst1.end(), my::Gen());
    my::generate(lst2.begin(), lst2.end(), my::Gen());
    EXPECT_TRUE(lst1 == lst2);
}

TEST(a, c5)
{
    const int SIZE = 10;
    std::list<int> lst1(SIZE);
    std::list<int> lst2(SIZE);
    std::generate_n(lst1.begin(), SIZE, my::Gen());
    my::generate_n(lst2.begin(), SIZE, my::Gen());
    EXPECT_TRUE(lst1 == lst2);
}

TEST(a, d5)
{
    std::list<int> lst1;
    lst1.push_back(1);
    lst1.push_back(2);
    lst1.push_back(3);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(5);
    lst1.push_back(6);
    
    std::list<int> lst2;
    lst2.push_back(1);
    lst2.push_back(2);
    lst2.push_back(3);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(5);
    lst2.push_back(6);
    
    
    std::copy(lst1.begin(), std::remove_if(lst1.begin(), lst1.end(), my::UnaryFunction1()), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(lst2.begin(),  my::remove_if(lst2.begin(), lst2.end(), my::UnaryFunction1()), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(lst1.begin(),  lst1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(lst2.begin(),  lst2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(lst1 == lst2);
}

TEST(a, e5)
{
    std::list<int> lst1;
    lst1.push_back(1);
    lst1.push_back(2);
    lst1.push_back(3);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(1);
    lst1.push_back(2);
    lst1.push_back(3);
    lst1.push_back(4);
    lst1.push_back(5);
    lst1.push_back(6);
    
    std::list<int> vec1(lst1.size());
    std::list<int> vec2(lst1.size());
    
    std::remove_copy_if(lst1.begin(), lst1.end(), vec1.begin(), my::UnaryFunction1());
    my::remove_copy_if(lst1.begin(), lst1.end(), vec2.begin(), my::UnaryFunction1());
    EXPECT_TRUE(vec1 == vec2);
}

TEST(a, f5)
{
    std::list<int> lst1;
    lst1.push_back(1);
    lst1.push_back(2);
    lst1.push_back(2);
    lst1.push_back(2);
    lst1.push_back(3);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(5);
    lst1.push_back(6);
    
    std::list<int> lst2;
    lst2.push_back(1);
    lst2.push_back(2);
    lst2.push_back(2);
    lst2.push_back(2);
    lst2.push_back(3);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(5);
    lst2.push_back(6);
    
    
    std::copy(lst1.begin(), std::unique(lst1.begin(), lst1.end()), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(lst2.begin(),  my::unique(lst2.begin(), lst2.end()), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(lst1.begin(),  lst1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(lst2.begin(),  lst2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(lst1 == lst2);
}

TEST(a, g5)
{
    std::list<int> lst1;
    lst1.push_back(1);
    lst1.push_back(2);
    lst1.push_back(2);
    lst1.push_back(2);
    lst1.push_back(3);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(5);
    lst1.push_back(6);
    
    std::list<int> lst2;
    lst2.push_back(1);
    lst2.push_back(2);
    lst2.push_back(2);
    lst2.push_back(2);
    lst2.push_back(3);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(5);
    lst2.push_back(6);
    
    
    std::copy(lst1.begin(), std::unique(lst1.begin(), lst1.end(), my::IsEqual()), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(lst2.begin(),  my::unique(lst2.begin(), lst2.end(), my::IsEqual()), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(lst1.begin(),  lst1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(lst2.begin(),  lst2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(lst1 == lst2);
}

TEST(a, m5)
{
    std::list<int> lst1;
    lst1.push_back(1);
    lst1.push_back(2);
    lst1.push_back(2);
    lst1.push_back(2);
    lst1.push_back(3);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(5);
    lst1.push_back(6);
    
    std::list<int> lst2;
    lst2.push_back(1);
    lst2.push_back(2);
    lst2.push_back(2);
    lst2.push_back(2);
    lst2.push_back(3);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(5);
    lst2.push_back(6);
    
    std::vector<int> vec1(lst1.size()); 
    std::vector<int> vec2(lst2.size()); 
    std::copy(vec1.begin(), std::unique_copy(lst1.begin(), lst1.end(), vec1.begin()), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(vec2.begin(),  my::unique_copy(lst2.begin(), lst2.end(), vec2.begin()), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    //std::copy(lst1.begin(),  lst1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    //std::copy(lst2.begin(),  lst2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(lst1 == lst2);
    EXPECT_TRUE(vec1 == vec2);
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
}

TEST(a, n5)
{
    std::list<int> lst1;
    lst1.push_back(1);
    lst1.push_back(2);
    lst1.push_back(2);
    lst1.push_back(2);
    lst1.push_back(3);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(4);
    lst1.push_back(5);
    lst1.push_back(6);
    
    std::list<int> lst2;
    lst2.push_back(1);
    lst2.push_back(2);
    lst2.push_back(2);
    lst2.push_back(2);
    lst2.push_back(3);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(4);
    lst2.push_back(5);
    lst2.push_back(6);
    
    
    std::vector<int> vec1(lst1.size()); 
    std::vector<int> vec2(lst2.size()); 
    std::copy(vec1.begin(), std::unique_copy(lst1.begin(), lst1.end(), vec1.begin(), my::IsEqual()), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(vec2.begin(),  my::unique_copy(lst2.begin(), lst2.end(), vec2.begin(), my::IsEqual()), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(lst1.begin(),  lst1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(lst2.begin(),  lst2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(lst1 == lst2);
    EXPECT_TRUE(vec1 == vec2);
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
}


TEST(a, b6)
{
    ::srand(::time(0));
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(6);
    
    std::vector<int> vec2;
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(3);
    vec2.push_back(4);
    vec2.push_back(5);
    vec2.push_back(6);
    
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    my::random_shuffle(vec1.begin(), vec1.end());
    std::random_shuffle(vec2.begin(), vec2.end());
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
}

TEST(a, c6)
{
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(6);
    
    std::vector<int> vec2;
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(3);
    vec2.push_back(4);
    vec2.push_back(5);
    vec2.push_back(6);
    
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    my::RandomGenerator a;
    my::random_shuffle(vec1.begin(), vec1.end(), a);
    std::random_shuffle(vec2.begin(), vec2.end(), a);
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
}

TEST(a, d6)
{
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(6);
    vec1.push_back(7);
    vec1.push_back(8);
    vec1.push_back(9);
    vec1.push_back(10);
    
    std::vector<int> vec2(vec1.size() + 3);
    
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    my::random_sample(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
    std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
}

TEST(a, e6)
{
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(6);
    vec1.push_back(7);
    vec1.push_back(8);
    vec1.push_back(9);
    vec1.push_back(10);
    
    std::vector<int> vec2(vec1.size() + 3);
    
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    my::random_sample_n(vec1.begin(), vec1.end(), vec2.begin(), 3);
    std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
}

TEST(a, f6)
{
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);
    vec1.push_back(6);
    vec1.push_back(7);
    vec1.push_back(8);
    vec1.push_back(9);
    vec1.push_back(10);
    
    std::vector<int> vec2(vec1.size() + 2);
    my::RandomGenerator a;
    
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    my::random_sample_n(vec1.begin(), vec1.end(), vec2.begin(), 9, a);
    std::copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
}


TEST(a, b7)
{
    std::vector<int> vec;
    vec.push_back(9);
    vec.push_back(4);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(2);
    
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::cout << *std::partition(vec.begin(), vec.end(), my::IsEven()) << std::endl; 
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
}

TEST(a, c7)
{
    std::vector<int> vec;
    vec.push_back(9);
    vec.push_back(4);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(2);
    
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    std::cout << *my::partition(vec.begin(), vec.end(), my::IsEven()) << std::endl; 
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
}

TEST(a, d7)
{
    std::vector<int> vec1;
    vec1.push_back(9);
    vec1.push_back(4);
    vec1.push_back(0);
    vec1.push_back(1);
    vec1.push_back(5);
    vec1.push_back(10);
    vec1.push_back(3);
    vec1.push_back(7);
    vec1.push_back(8);
    vec1.push_back(2);
    
    std::vector<int> vec2(vec1);
    
    std::vector<int>::iterator it = std::stable_partition(vec1.begin(), vec1.end(), my::IsEven());
    std::vector<int>::iterator jt = my::stable_partition(vec2.begin(), vec2.end(), my::IsEven());
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(*it == *jt);
}

TEST(a, e7)
{
    std::vector<int> vec1;
    vec1.push_back(0);
    vec1.push_back(0);
    vec1.push_back(9);
    vec1.push_back(4);
    vec1.push_back(0);
    vec1.push_back(1);
    vec1.push_back(5);
    vec1.push_back(10);
    vec1.push_back(3);
    vec1.push_back(7);
    vec1.push_back(8);
    vec1.push_back(2);
    
    std::vector<int> vec2(vec1);
    
    std::vector<int>::iterator it = std::stable_partition(vec1.begin(), vec1.end(), my::IsEven());
    std::vector<int>::iterator jt = my::stable_partition(vec2.begin(), vec2.end(), my::IsEven());
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(*it == *jt);
}


TEST(a, b8)
{
    std::list<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(4);
    a.push_back(6);
    a.push_back(6);
    a.push_back(7);
    a.push_back(9);
    std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(std::lower_bound(a.begin(), a.end(), 5) == my::lower_bound(a.begin(), a.end(), 5));
    EXPECT_TRUE(std::lower_bound(a.begin(), a.end(), 0) == my::lower_bound(a.begin(), a.end(), 0));
    EXPECT_TRUE(std::lower_bound(a.begin(), a.end(), 10) == my::lower_bound(a.begin(), a.end(), 10));
    EXPECT_TRUE(std::upper_bound(a.begin(), a.end(), 10) == my::upper_bound(a.begin(), a.end(), 10));
    EXPECT_TRUE(std::upper_bound(a.begin(), a.end(), 0) == my::upper_bound(a.begin(), a.end(), 0));
    EXPECT_TRUE(std::upper_bound(a.begin(), a.end(), 5) == my::upper_bound(a.begin(), a.end(), 5));
    EXPECT_TRUE(std::equal_range(a.begin(), a.end(), 5) == my::equal_range(a.begin(), a.end(), 5));
}

TEST(a, c8)
{
    std::list<int> a1;
    a1.push_back(1);
    a1.push_back(3);
    a1.push_back(4);
    a1.push_back(6);
    a1.push_back(6);
    a1.push_back(7);
    a1.push_back(9);
    
    std::list<int> a2;
    a2.push_back(0);
    a2.push_back(0);
    a2.push_back(4);
    a2.push_back(4);
    a2.push_back(8);
    a2.push_back(9);
    a2.push_back(11);
   
    std::vector<int> vec1(a1.size() + a2.size()); 
    std::vector<int> vec2(a1.size() + a2.size()); 
    my::merge(a1.begin(), a1.end(), a2.begin(), a2.end(), vec1.begin());
    std::merge(a1.begin(), a1.end(), a2.begin(), a2.end(), vec2.begin());
    EXPECT_TRUE(vec1 == vec2);
}

TEST(a, d8)
{
    std::vector<int> a1;
    a1.push_back(6);
    a1.push_back(7);
    a1.push_back(9);
    a1.push_back(1);
    a1.push_back(3);
    a1.push_back(4);
    a1.push_back(6);
    
    std::vector<int> a2(a1);
    
    my::inplace_merge(a1.begin(), a1.begin() + 3, a1.end());
    std::inplace_merge(a2.begin(), a2.begin() + 3, a2.end());
    EXPECT_TRUE(a1 == a2);
}


template <typename InputIterator>
void
print(InputIterator first, InputIterator last, std::ostream& out = std::cout)
{
    for (InputIterator it = first; it != last; ++it) {
        out << *it << " ";
    }
}

TEST(a, Include)
{
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    
    EXPECT_TRUE(my::includes(l.begin(), l.end(), v.begin(), v.end()));
}

TEST(a, Union)
{
    std::list<int> l;
    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    
    std::vector<int> result(1000);
    std::vector<int>::iterator it = my::set_union(l.begin(), l.end(), v.begin(), v.end(), result.begin());
    result.resize(it - result.begin());
    std::stringstream ss;
    print(result.begin(), result.end(), ss);
    EXPECT_EQ(ss.str(), "0 1 2 3 4 5 6 7 8 9 ");
}

TEST(a, Intersection)
{
    std::list<int> l;
    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    
    std::vector<int> result(1000);
    std::vector<int>::iterator it = my::set_intersection(l.begin(), l.end(), v.begin(), v.end(), result.begin());
    result.resize(it - result.begin());
    std::stringstream ss;
    print(result.begin(), result.end(), ss);
    EXPECT_EQ(ss.str(), "1 2 7 ");
}

TEST(a, Difference)
{

    std::list<int> l;
    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.push_back(11);
    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
                                                    
                                         
    std::vector<int> result(1000);
    std::vector<int>::iterator it = my::set_difference(l.begin(), l.end(), v.begin(), v.end(), result.begin());
    result.resize(it - result.begin());
    std::stringstream ss;
    print(result.begin(), result.end(), ss);
    EXPECT_EQ(ss.str(), "0 3 4 5 6 11 ");
}

TEST(a, SymDifference)
{

    std::list<int> l;
    l.push_back(0);
    l.push_back(1);
    l.push_back(1);
    l.push_back(1);
    l.push_back(2);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
                                                         
                                         
    std::vector<int> result(1000);
    std::vector<int>::iterator it = my::set_symmetric_difference(l.begin(), l.end(), v.begin(), v.end(), result.begin());
    result.resize(it - result.begin());
    std::stringstream ss;
    print(result.begin(), result.end(), ss);
    EXPECT_EQ(ss.str(), "0 1 1 2 3 4 5 6 8 9 ");
}

TEST(a, b9)
{
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);

    std::vector<int> vec2(vec1);

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::next_permutation(vec1.begin(), vec1.end()) == my::next_permutation(vec2.begin(), vec2.end()));
}

TEST(a, c9)
{
    std::vector<int> vec1;
    vec1.push_back(4);
    vec1.push_back(3);
    vec1.push_back(2);
    vec1.push_back(1);

    std::vector<int> vec2(vec1);

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_TRUE(std::prev_permutation(vec1.begin(), vec1.end()) == my::prev_permutation(vec2.begin(), vec2.end()));
}

TEST(a, d9)
{
    std::vector<int> vec1;
    vec1.push_back(4);
    vec1.push_back(3);
    vec1.push_back(2);
    vec1.push_back(1);

    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
    EXPECT_TRUE(std::accumulate(vec1.begin(), vec1.end(), 0) == my::accumulate(vec1.begin(), vec1.end(), 0));
}

TEST(a, b10)
{
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);

    std::list<int> lst1;
    lst1.push_back(6);
    lst1.push_back(2);
    lst1.push_back(8);
    lst1.push_back(6);
    lst1.push_back(4);
    EXPECT_TRUE(std::inner_product(vec1.begin(), vec1.end(), lst1.begin(), 0) ==
                my::inner_product(vec1.begin(), vec1.end(), lst1.begin(), 0));
}

TEST(a, c10)
{
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);

    std::list<int> lst1;
    std::list<int> lst2;
    std::partial_sum(vec1.begin(), vec1.end(), lst1.begin());
    my::partial_sum(vec1.begin(), vec1.end(), lst2.begin());
    EXPECT_TRUE(lst1 == lst2);
}

TEST(a, d10)
{
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);
    vec1.push_back(5);

    std::list<int> lst1;
    std::list<int> lst2;
    std::adjacent_difference(vec1.begin(), vec1.end(), lst1.begin());
    my::adjacent_difference(vec1.begin(), vec1.end(), lst2.begin());
    EXPECT_TRUE(lst1 == lst2);
}

TEST(a, e10)
{
    EXPECT_TRUE(std::pow(7, 8) == my::power(7, 8));
    EXPECT_TRUE(std::pow(-9, 4) == my::power(-9, 4));
    EXPECT_TRUE(std::pow(-3, 7) == my::power(-3, 7));
}


int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
