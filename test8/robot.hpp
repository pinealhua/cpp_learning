#pragma once//防止同一个头文件被重复包含

class Robot
{
private:
    double speed;
    bool motor_on;

public:
    Robot(double initial_speed);

    void start();
    void stop();
    void printStatus();
};