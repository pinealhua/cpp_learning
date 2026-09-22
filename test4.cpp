//结构体


//结构体可以放函数，这个函数叫成员函数
/*
struct Robot
{
    double speed;
    bool motor_on;

    void stop()//同一个函数定义依旧可以作用于不同对象的数据
    {
        speed = 0.0;
        //或者可以写成 this->speed = 0.0;    this本质上是一个指向当前对象的指针
    }
};
Robot robot1;

robot1.speed = 3.0;

robot1.stop();//之后speed就是0了


以上是结构体   */

/*类
public 公共，谁都能改 

private只有这个类的成员函数可以使用
class Robot
{
private:
    double speed;

public:
    void setSpeed(double new_speed)
    {
        speed = new_speed;
    }

    double getSpeed()
    {
        return speed;
    }
};
想改变这个speed只能 robot.setSpeed(3.0);

其实struct和class功能几乎一样。struct默认里面的成员都是public，class不是。反正怎么写都合法，主要是语法习惯，class就是会有内部操作

*/

/*构造函数

创建一个类的对象，通过构造函数进行初始化
class Robot
{
public:
    double speed;
    bool motor_on;

    Robot()
    {
        speed = 0.0;
        motor_on = false;
    }
};
构造函数是创建对象时候自动调用的
Robot robot;自动初始化了

如果构造函数需要进行传参
Robot robot1(2.5);
Robot robot2(5.0); 把括号里面的参数交给构造函数

*/

#include <iostream>
class Robot
{
    public:
double speed;
bool motor_on;

void start()
{
    motor_on = true;

}
void stop()
{
    motor_on = false;
    speed=0;

}
void printStatus()
{
std::cout<<motor_on<<std::endl;
std::cout<<speed<<std::endl;

}


};
Robot robot_test;
int main()
{
    robot_test.start();
    robot_test.stop();
    robot_test.printStatus();

    return 0;
}
