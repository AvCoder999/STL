#include "headers/Stack.hpp"
#include "headers/CustomClass.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(IntStack, StackFunctionsTets)
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_TRUE(s.top() == 3);
    EXPECT_TRUE(s.size() == 3);
    
    s.pop();
    EXPECT_TRUE(s.top() == 2);
    EXPECT_TRUE(s.size() == 2);
    
    s.pop();
    EXPECT_TRUE(s.top() == 1);
    EXPECT_TRUE(s.size() == 1);
    
    s.pop();
    EXPECT_TRUE(s.size() == 0);
    EXPECT_TRUE(s.empty());
    /// EXPECT_DEATH(s.top(), ".*");
    /// EXPECT_DEATH(s.pop(), ".*");

}

TEST(IntStack, relationalOperators)
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    std::stringstream ss;
    ss << s1;
    EXPECT_STREQ(ss.str().c_str(), "{ 4 3 2 1 }");

    std::istringstream is("1 2 3 4");
    Stack<int> s2;
    is >> s2;
    ss.str("");
    ss << s2;
    EXPECT_STREQ(ss.str().c_str(), "{ 4 3 2 1 }");
    EXPECT_TRUE(s1 == s2);

    s2.pop();
    EXPECT_TRUE(s1 > s2);
    
    Stack<int> s3(s1);
    ss.str("");
    ss << s3;
    EXPECT_STREQ(ss.str().c_str(), "{ 4 3 2 1 }");

    s3 = s2;
    ss.str("");
    ss << s3;
    EXPECT_STREQ(ss.str().c_str(), "{ 3 2 1 }");
}

TEST(CustomClassStack, relationalOperators)
{
    Stack<CustomClass> s1;
    s1.push(CustomClass(1));
    s1.push(CustomClass(2));
    s1.push(CustomClass(3));
    s1.push(CustomClass(4));
    std::stringstream ss;
    ss << s1;
    EXPECT_STREQ(ss.str().c_str(), "{ 4 3 2 1 }");

    std::istringstream is("1 2 3 4");
    Stack<CustomClass> s2;
    is >> s2;
    ss.str("");
    ss << s2;
    EXPECT_STREQ(ss.str().c_str(), "{ 4 3 2 1 }");
    EXPECT_TRUE(s1 == s2);

    s2.pop();
    EXPECT_TRUE(s1 > s2);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

