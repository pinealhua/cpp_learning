#include<iostream>
#include<string>

    int robot_id = 1;
    double speed = 1.5;
    bool motor_on = true; //bool值，判断真假的变量类型
    std::string robot_name = "sentinel";//字符串
int main()
{
   
//  std::string speed_ = "speed:";
    speed = 2.0;
    motor_on = false;

    std::cout << "robot_id:" << robot_id << std::endl;
    std::cout << "robot_speed:" << speed << std::endl;
    std::cout << "motor_status:" << motor_on << std::endl;
    std::cout << "robot_name:" << robot_name << std::endl;

    return 0;
}