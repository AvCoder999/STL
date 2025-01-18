#ifndef __CUSTOM_CLASS_HPP__
#define __CUSTOM_CLASS_HPP__

#include <iostream>

 class CustomClass
{
public:
    CustomClass() : data_(0) { /*std::cout << "Default Ctor" << std::endl;*/ }
    CustomClass(const int data) : data_(data) { /*std::cout << "Parameter Ctor" << std::endl;*/ }
    CustomClass(const CustomClass& rhv) : data_(rhv.data_) { /*std::cout << "Copy Ctor" << std::endl;*/ }
    ~CustomClass() { /*std::cout << "Destructor" << std::endl;*/ };
    const CustomClass& operator=(const CustomClass& rhv) { data_ = rhv.data_; /*std::cout << "Assignment" << std::endl;*/ return *this; }
    bool operator==(const CustomClass& rhv) const { return data_ == rhv.data_; }
    bool operator!=(const CustomClass& rhv) const { return data_ != rhv.data_; }
    bool operator<(const CustomClass& rhv) const  { return data_ < rhv.data_;  }
    bool operator>(const CustomClass& rhv) const  { return rhv < *this;        }
    bool operator>=(const CustomClass& rhv) const { return !((*this) < rhv);   }
    bool operator<=(const CustomClass& rhv) const { return !(rhv < *this);     }

private:
    int data_;

};

#endif /// __CUSTOM_CLASS_HPP__

