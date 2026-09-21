#include<iostream>
double obstacle_distance = 5;
bool motor_on = true;
int main()
{
    if(!motor_on)
    {
     std::cout << "Motor is off" << std::endl;
    }
    else if(obstacle_distance<=1.0f)
    {
        std::cout << "emergency stop" << std::endl;
    }

    return 0;
}