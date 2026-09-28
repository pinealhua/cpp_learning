/*

智能指针

裸指针是什么
Robot robot;
Robot* ptr = &robot;

ptr->stop();
这里ptr只保存robot的地址不负责robot的生命周期。智能指针就是不仅保存地址，还顺便管理这个对象什么时候该被销毁


#include <memory>

auto robot = std::make_unique<Robot>();
这里std::make_unique<Robot>() 会创建一个Robot对象，然后返回std::unique_ptr<Robot>
不过因为返回类型比较长，简写成auto编译器就会自动识别到这个类型

访问对象的方法和普通指针一样，都是robot->stop();
所以说裸指针Robot*和std::unique_ptr<Robot>和std::shared_ptr<Robot>都可以用->来访问对象

unique就是独占，同一时刻只能有一个unique_ptr拥有这个对象

虽然不能进行复制，但是可以交出所有权
auto robot1 = std::make_unique<Robot>();
auto robot2 = std::move(robot1);
之前是robot1 -> Robot  move之后，robot1就是nullptr  robot2->Robot  之后robot1不再拥有对象
区别一下，auto robot1 = std::make_unique<Robot>();  auto robot2 = std::make_unique<Robot>();
这个当然合法，因为本质上创建了两个Robot，每一个Robot都指向唯一对象。禁止的是一个对象同时被两个unique_ptr拥有

void test()
{
    auto robot = std::make_unique<Robot>();

    robot->start();
}
    在这里执行到}的时候，离开作用域robot智能指针被销毁 拥有的Robot就自动被销毁，不用手动delete robot

std::shared_ptr和std::unique_ptr一样，都是智能指针。
auto robot = std::make_shared<Robot>();
完整类型就是std::shared_ptr<Robot> robot = std::make_shared<Robot>();
最大区别就是unique是一个所有者，shared可以有多个所有者

auto robot1 = std::make_shared<Robot>();

auto robot2 = robot1;
这个是合法的  是两个shared_ptr一起指向拥有同一个Robot

但是shared_ptr由于有多个指针一起指向同一个对象，所以不能像unique_ptr那样结束就销毁
内部会维护一个引用次数  reference count
比如说auto robot1 = std::make_shared<Robot>();
现在 Robot所有者数量是1。
然后auto robot2 = robot1； 这时候Robot所有者数量就是2
如果robot2 = nullptr；  所有者数量就变成1
这时候robot1 = nullptr  所有者数量变成0，这时候对象自动销毁


std::make_shared<Robot>()就是创建一个用于管理Robot类型对象的shared_ptr
std::make_shared<int>(10) 创建一个值为10的int
std::make_shared<Robot>() 创建一个Robot。  如果构造函数需要传递参数，那么auto robot = std::make_shared<Robot>(3.0);
所以就相当于make_shared<Robot>(3.0)调用了Robot(3.0)

和普通对象的区别
Robot robot(3.0);  robot.stop();  对象本身就在robot这个变量里面
auto robot = std::make_shared<Robot>(3.0);
robot->stop();
这里robot本质就是shared_ptr<Robot>  里面管理一个Robot  所以访问方式不同，这里用的是->

nullptr
std::shared_ptr<Robot> robot = nullptr;表示目前没有管理任何Robot，不能直接 robot->stop();
可以if (robot != nullptr)
{
    robot->stop();
}
或者if (robot)  理解成robot当前是否有效指向某个对象
{
    robot->stop();
}
为什么要引入shared_ptr是因为ROS 2 里很多对象可能需要被框架、执行器、回调、用户代码等多个地方共同持有
生命周期如果只有一个持有者的话会很麻烦，很多地方都需要确保这个node现在不能被销毁。

一般来说，能独占就用unique_ptr，确实需要共享所有权的时候用shared_ptr


//补充知识
裸指针

Robot robot;

Robot* ptr = &robot;
这里robot只是一个普通变量，ptr只是记住了robot的地址，并没有创建robot也不拥有robot
所以说到了最后的}就是自动销毁，不需要进行delete

Robot* ptr = new Robot();  相当于告诉系统，给我另外申请一块内存，在那里创建一个 Robot，然后把地址给我。
void test()
{
    Robot* ptr = new Robot();
}
运行到最后的时候，局部变量确实没了，但是Robot不会直接被销毁，因为申请的内存空间还在。
但是由于你的ptr被销毁，所以说你就不知道Robot此时在哪里了，这就是内存泄漏
所以说如果new，需要销毁new创建的对象，并且释放动态内存
Robot* ptr = new Robot();

ptr->work();

delete ptr;

shared_ptr<Robot> 里的 Robot 是之前自己定义的类，或者是任何合适的类型都可以

为什么要new和智能指针，主要诉求是因为有的对象需要活得比当前作用域更久
Robot* createRobot()
{
    Robot robot;

    return &robot;   // 创建一个robot的同时，把地址返回去。但是这么写的话只能返回空地址，robot在出函数的时候就被销毁了
}
所以说就可以写
std::unique_ptr<Robot> createRobot()
{
    return std::make_unique<Robot>();
}
auto robot = createRobot();   虽然这个函数结束了，但是Robot依然存在，因为生命周期是跟着返回出去的unique_ptr
如果需求就是生命周期简单就在当前作用域，就用普通对象。需要跨作用域，共享生命周期，需要动态对象


*/


#include <iostream>
#include <memory>

int main()
{
    auto robot1 = std::make_shared<int>(10);

    std::cout << robot1.use_count() << std::endl;

    auto robot2 = robot1;

    std::cout << robot1.use_count() << std::endl;

    return 0;
}



/*
示例代码
#include <iostream>
#include <memory>

class Robot
{
public:
    Robot()
    {
        std::cout << "Robot created" << std::endl;
    }

    ~Robot()
    {
        std::cout << "Robot destroyed" << std::endl;
    }

    void work()
    {
        std::cout << "Robot working" << std::endl;
    }
};

int main()
{
    auto robot1 = std::make_shared<Robot>();

    std::cout << robot1.use_count() << std::endl;

    {
        auto robot2 = robot1;

        std::cout << robot1.use_count() << std::endl;

        robot2->work();
    }

    std::cout << robot1.use_count() << std::endl;

    return 0;
}

第二个小的{}就是更小的作用域
{
    auto robot2 = robot1;
}
进入{的时候，创建robot2 引用计数+1  离开}的时候，robot2被销毁，引用计数-1

robot在最后main的}退出之后被销毁，在销毁一个Robot对象的过程中，会自动调用它的析构函数~Robot()
在main离开作用域的过程中，会销毁局部对象，销毁完成后，main彻底结束
析构函数就是对象临死前自动执行的清理函数。

*/