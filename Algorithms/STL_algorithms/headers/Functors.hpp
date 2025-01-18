#ifndef __FUNCTORS_HPP__
#define __FUNCTORS_HPP__

#include <cstdlib>

namespace my {

struct Gen {
    int operator()() const { 
        static int counter = 0; 
        return ++counter % 10;
    }
};

struct RandomGenerator {
    int operator()(const int max) const {
        return std::rand() % max;
    }
};

struct UnaryFunction1 {
    bool operator()(const int a) const { return a % 3 == 0; }
};

struct BinaryFunction1 {
    bool operator()(const int a, const int b) const { return a % 2 == b % 3; }
};

struct UnaryFunction {
    int operator()(const int a) const { return a * 2; }
};

struct BinaryFunction {
    int operator()(const int a, const int b) const {
        return a * b;
    }
};

struct IsEqual {
    bool operator()(const int a, const int b) const { return a == b; }
};

struct IsEven {
    bool operator()(const int a) const { return a % 2 == 0; }
};

} /// end of namespace my

#endif /// __FUNCTORS_HPP__

