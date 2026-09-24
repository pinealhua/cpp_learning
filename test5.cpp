/*
继承   在已有类型的基础上，继续增加功能，而不是把已有代码重新复制一遍 
继承可以把权限收紧，但不会把父类的权限放宽

以上节课robot类为例，有speed变量和stop函数
此时想做一个特殊机器人，它除了speed和stop需要额外增加一个功能scan()
class SentryRobot : public Robot
{
public:
    void scan()
    {
        std::cout << "Scanning..." << std::endl;
    }
};
就可以这样去写
因为speed和stop和robot完全重复，没必要再去复制粘贴一遍
这里的意思就是SentryRobot 是一种 Robot。
SentryRobot sentry;  不仅有自己定义的scan(),还有从robot继承来的speed
sentry.scan();
sentry.speed = 3.0;
sentry.stop();
这是完全合法的
继承可以一层一层嵌套，也就是说SentryRobot既可以是子类也可以是别人的父类
但是尽量少继承，继承越少越容易维护

class SentryRobot : public Robot这里sentryrobot是robot的子类，继承方式是公有继承
就是Robot以前的成员如果是public，那么sentry里面依旧是public  protected也是protected
class SentryRobot : protected Robot  protected继承 Robot 的 public到了 SentryRobot 变成 protected
所以父类本来公开的函数，子类也不能外部直接调用了
class SentryRobot : private Robot    private继承 Robot的public和protected都是private
class SentryRobot : Robot省略继承方式，默认是private继承

protected适合用户不希望直接操作，但是子类可以继续使用
父类的成员函数可以直接访问，子类的成员函数也能直接访问，但是无法通过外部更改

class Robot
{
private:
    void secretFunction();

protected:
    void updateMotor();

public:
    void stop();
};

在main里面定义一个对象Robot robot; 那么调用的适合只能调用public的成员函数，因为是在类的外部进行调用的
private就是只有Robot自己的成员函数可以调用

class Robot
{
private:
    void secretFunction()
    {
    }
public:
    void stop()
    {
        secretFunction();   // ✅
        std::cout << "stop" << std::endl;
    }
};
这时候外部如果调用 robot.stop();是完全可以的，调用之后进入Robot自己的成员函数，然后stop调用secret_function

*/

#include <iostream>

class Robot
{
public:
    Robot()
    {
        std::cout << "Robot constructor" << std::endl;
    }
};

class SentryRobot : public Robot
{
public:
    SentryRobot()
    {
        std::cout << "SentryRobot constructor" << std::endl;
    }
};

int main()
{
    SentryRobot sentry;

    return 0;
}
//创建子类对象时，先构造父类部分，再构造子类自己的部分
//先输出Robot的部分，再输出SentryRobot的部分，因为你sentryrobot首先是一个robot，把robot部分构建好了才能继续构建sentry的部分

/*
以上是父类构造函数不需要传参的情况，但是事实上需要传参
class Robot
{
public:
    Robot(double initial_speed)
    {
        std::cout << "Robot speed: "
                  << initial_speed
                  << std::endl;
    }
};

那子类如果不传参就会报错，因为你没有把父类的部分构造完全。所以子类要在自己的构造函数初始化里面明确调用父类构造函数
class SentryRobot : public Robot
{
public:
    SentryRobot()
        : Robot(2.5)
    {
    }
};

这里  : Robot(2.5)就是在构造 SentryRobot 之前，先用 2.5 调用父类的 Robot(double) 构造函数

子类也可以先接受参数，再传给父类
class SentryRobot : public Robot
{
public:
    SentryRobot(double speed)
        : Robot(speed)
    {
        std::cout << "Sentry created" << std::endl;
    }
};
SentryRobot sentry(3.0);
这个和初始化成员变量可能会同时出现

class SentryRobot : public Robot
{
private:
    bool scanning;

public:
    SentryRobot(double speed)
        : Robot(speed),
          scanning(false)
    {
    }
};
用 speed 构造父类 Robot，同时把自己的成员 scanning 初始化为 false。
*/

