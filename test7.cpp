/*
纯虚函数和抽象类
class Robot
{
public:
    virtual void work() = 0;
};
这个虚函数没有具体实现，子类需要提供自己的实现。这种就是纯虚函数
有纯虚函数的类叫抽象类

这个时候Robot robot;会直接报错，因为抽象类不能直接写一个对象。
子类必须要完成这个虚函数
class EngineerRobot : public Robot
{
public:
    void work() override
    {
        std::cout << "Engineer repairing" << std::endl;
    }
};
这样才算合法
如果子类不完成这个虚函数，那么子类依然是抽象类，不能创建对象
class SentryRobot : public Robot
{
};
这时候SentryRobot sentry; 就会报错，原因和上面的一样

抽象类当然也可以有别的普通成员
class Robot
{
protected:
    double speed;

public:
    void stop()
    {
        speed = 0.0;
    }

    virtual void work() = 0;
};
stop()这个函数就是已经实现好的普通函数，work就是需要子类自己实现的虚函数
class SentryRobot : public Robot
{
public:
    void work() override
    {
        std::cout << "Scanning" << std::endl;
    }
};
子类既可以调用现成的继承好的 SentryRobot.stop，又要自己实现work()



接口
c++通过只包含纯虚函数的抽象类来表达接口
class Controller
{
public:
    virtual void configure() = 0;
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void computeCommand() = 0;
};

这个父类表达作为一个controller至少需要实现的这四个功能。所以说
class MyController : public Controller
{
public:
    void configure() override
    {
    }

    void activate() override
    {
    }

    void deactivate() override
    {
    }

    void computeCommand() override
    {
    }
};
这个就是一个具体实现




*/

#include <iostream>

class Controller
{
public:
    virtual void computeCommand() = 0;
};

class DWBController : public Controller
{
public:
    void computeCommand() override
    {
        std::cout << "DWB" << std::endl;
    }
};

class MPPIController : public Controller
{
public:
    void computeCommand() override
    {
        std::cout << "MPPI" << std::endl;
    }
};

int main()
{
    Controller* controller;
    DWBController dwb;
    MPPIController mppi;
    controller = &dwb;   
    controller = &mppi;   //在这里看controller指向谁，决定了下面的computeCommand执行谁的
    controller->computeCommand();


    return 0;
}

/*
通常可以这样，后续不用再次判断应该用哪个，在前面进行配置选择就行
Controller* controller;

if (mode == 0)
{
    controller = &dwb;
}
else
{
    controller = &mppi;
}


*/
