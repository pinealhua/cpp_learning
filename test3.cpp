//指针就是能保存地址的变量
// double* ptr = &speed;  ptr 是一个“指向 double 的指针”，现在它指向 speed

#include<iostream>

int main()
{
    int speed = 2;
    int* ptr = &speed;
    std::cout<<speed<<std::endl;
    std::cout<<&speed<<std::endl;
    std::cout<<ptr<<std::endl;
    std::cout<<*ptr<<std::endl;
    std::cout<<&ptr<<std::endl;
    return 0;
}