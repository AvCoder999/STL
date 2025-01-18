#include "headers/Queue.hpp"
#include "headers/CustomClass.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

TEST(IntQueue, QueueFunctionsTets)
{
    Queue<int, std::vector<int> > s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_TRUE(s.front() == 1);
    EXPECT_TRUE(s.back() == 3);
    EXPECT_TRUE(s.size() == 3);
    
    s.pop();
    EXPECT_TRUE(s.front() == 2);
    EXPECT_TRUE(s.back() == 3);
    EXPECT_TRUE(s.size() == 2);
    
    s.pop();
    EXPECT_TRUE(s.front() == 3);
    EXPECT_TRUE(s.back() == 3);
    EXPECT_TRUE(s.size() == 1);
    
    s.pop();
    EXPECT_TRUE(s.size() == 0);
    EXPECT_TRUE(s.empty());

    /// EXPECT_DEATH(s.front(), ".*");
    /// EXPECT_DEATH(s.pop(), ".*");
}

TEST(IntQueue, relationalOperators)
{
    Queue<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    std::stringstream ss;
    ss << s1;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 }");

    std::istringstream is("1 2 3 4");
    Queue<int> s2;
    is >> s2;
    
    ss.str("");
    ss << s2;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 }");
    EXPECT_TRUE(s1 == s2);
    
    s2.pop();
    ss.str("");
    ss << s2;
    EXPECT_STREQ(ss.str().c_str(), "{ 2 3 4 }");
    EXPECT_TRUE(s1 < s2);
    
    Queue<int> s3(s1);
    ss.str("");
    ss << s3;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 }");
    
    s3 = s2;
    ss.str("");
    ss << s3;
    EXPECT_STREQ(ss.str().c_str(), "{ 2 3 4 }");
}

TEST(CustomClassQueue, relationalOperators)
{
    Queue<CustomClass> s1;
    s1.push(CustomClass(1));
    s1.push(CustomClass(2));
    s1.push(CustomClass(3));
    s1.push(CustomClass(4));
    std::stringstream ss;
    ss << s1;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 }");

    std::istringstream is("1 2 3 4");
    Queue<CustomClass> s2;
    is >> s2;
    ss.str("");
    ss << s2;
    EXPECT_STREQ(ss.str().c_str(), "{ 1 2 3 4 }");
    EXPECT_TRUE(s1 == s2);

    s2.pop();
    EXPECT_TRUE(s1 < s2);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

