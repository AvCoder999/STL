#include "headers/HeapFunctions.hpp"
#include <gtest/gtest.h>
#include <sstream>
    
void
print(int* a, const int size) 
{
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
}

TEST(Heap, make_heap) 
{
    const int size = 8;
    int a[size] = {1, 5, 9, 7, 2, 6, 3, 4};
    EXPECT_TRUE(!my::is_heap(a, a + size));//, std::less<int>()));
    my::make_heap(a, a + size);
    print(a, size); 
    EXPECT_TRUE(my::is_heap(a, a + size));
}

TEST(Heap, pushPop)
{
    const int size = 8;
    int a[size] = {1, 5, 9, 7, 2, 6, 3, 4};
    
    my::make_heap(a, a + 4);
    my::push_heap(a, a + 5);
    my::push_heap(a, a + 6);
    my::push_heap(a, a + 7);
    my::push_heap(a, a + size);
    EXPECT_TRUE(my::is_heap(a, a + size));
    
    my::pop_heap(a, a + size);
    my::pop_heap(a, a + size - 1);
    my::pop_heap(a, a + size - 2);
    my::pop_heap(a, a + size - 3);
    my::pop_heap(a, a + size - 4);
    my::pop_heap(a, a + size - 5);
    my::pop_heap(a, a + size - 6);
    my::pop_heap(a, a + size - 7);
}

TEST(Heap, sort)
{
    const int size = 8;
    int a[size] = {1, 5, 9, 7, 2, 6, 3, 4};
    
    my::make_heap(a, a + 4);
    my::push_heap(a, a + 5);
    my::push_heap(a, a + 6);
    my::push_heap(a, a + 7);
    my::push_heap(a, a + size);
        
    EXPECT_TRUE(my::is_heap(a, a + size));
        
    my::sort_heap(a, a + size); 
    print(a, size); 
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

