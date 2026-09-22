//指针就是能保存地址的变量
// double* ptr = &speed;  ptr 是一个“指向 double 的指针”，现在它指向 speed
// ptr就是地址，*ptr是变量本身
#include<iostream>
double robot_speed = 3.0;
void energencystop(double* speed);
int main()
{
   
    
    energencystop(nullptr);

    // *ptr = 6;
    std::cout<<robot_speed<<std::endl;
  
    

    return 0;

}
void energencystop(double* speed)
{
    if(speed!=nullptr)
    *speed=0;

}
//if (ptr != nullptr && *ptr > 0)  如果ptr不是空指针，那么才会看后面。避免空指针带来的野指针