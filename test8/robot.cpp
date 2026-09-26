/*
.hpp、.cpp 与类的声明/实现分离

头文件与资源文件主函数分离
Robot.hpp     ← 告诉别人“Robot 有什么”
Robot.cpp     ← 告诉编译器“Robot 具体怎么实现”
main.cpp      ← 使用 Robot

hpp文件里面全是声明，放类定义、函数声明、接口信息
*/


#include "Robot.hpp"
#include <iostream>

Robot::Robot(double initial_speed)
    : speed(initial_speed), motor_on(true)
{
}

void Robot::start() //这里的：：是作用域解析运算符  
{
motor_on = true;
}

void Robot::stop()//就是robot这个类的stop，需要告诉编译器stop()属于哪个类

{
    speed = 0.0;
    motor_on = false;
}

void Robot::printStatus()
{
    std::cout << "Speed: " << speed << std::endl;
    std::cout << "Motor: " << motor_on << std::endl;
}