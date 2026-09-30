/*
lambda和callback
传统函数大部分都是全局，lambda 允许你直接在需要的地方定义一个“小函数”
int main()
{
    auto sayHello = []()
    {
        std::cout << "Hello" << std::endl;
    };

    sayHello();
}
运行效果和定义函数实现完全一致。

sayhello这里实现和普通函数不一样，在传参数之前要有一个[]
()一样可以传参
auto printDistance = [](double distance)
{
    std::cout << distance << std::endl;
};
printDistance(1.5);

lambda一样也可以有返回值
auto isDangerous = [](double distance)
{
    return distance < 1.0;
};
编译器就能从返回值推算出auto类型是bool
bool result = isDangerous(0.5);

lambda具体意义是什么呢
有些行为只在某些地方只用一次，那么这样写会比普通函数更方便也更简洁


回调函数
先把“以后要执行的函数”交给另一个东西，等某件事情发生以后，它再回来调用这个函数
和普通函数的区别就是，普通函数明确需要你进行函数的调用，回调函数虽然也要调用，但实际上是系统帮你调用
比如说现在有个激光雷达系统，收到了一个 distance<0.5的消息
可以提前给他一个行为
auto callback = [](double distance)
{
    if (distance < 1.0)
    {
        std::cout << "Danger!" << std::endl;
    }
};
这样在收到距离之后，雷达系统就会执行输出danger
回调函数怎么进入呢，负责处理传感器数据的那段程序，发现新数据到了，然后主动调用你之前登记好的 callback
先把回调函数写好，再把它注册给 ROS。
至于“消息什么时候到”“什么时候真正调用回调”，通常由 ROS 2 的通信系统和 Executor 来处理

lambda里面的[]叫做捕获列表
int main()
{
    double threshold = 1.0;

    auto check = [](double distance)
    {
        if (distance < threshold)
        {
            std::cout << "Danger" << std::endl;
        }
    };
}
这里会报错，因为threshold在main的作用域里面，lambda有自己的作用域，不能用外面的局部变量
捕获列表就是告诉lambda需要把外面的变量带到里面的作用域

auto check = [threshold](double distance)
{
    if (distance < threshold)
    {
        std::cout << "Danger" << std::endl;
    }
};
这样就是捕获外面的threshold，就能正常运行了
如果有多个变量需要捕获，使用逗号隔开即可
还有[=]表示需要用到的变量，默认按值捕获  [&]表示要用到的变量按引用捕获
double threshold = 1.0;
std::string name = "laser";

auto callback = [=](double distance)
{
    std::cout << name << std::endl;

    if (distance < threshold)
    {
        std::cout << "Danger" << std::endl;
    }
};
这里threshold和name都能用

[this]捕获this
class Robot
{
private:
    double speed = 3.0;

public:
    void setup()
    {
        auto callback = [this]()
        {
            std::cout << speed << std::endl;
        };

        callback();
    }
};
因为这个时候lambda想要使用Robot对象里面的speed，就要把this捕获进来
std::cout << speed; 本质上就是 std::cout << this->speed;

[this]到底捕获了什么
捕获的不是整个对象，捕获的是当前对象的this指针，还是this->Robot对象
所以lambda内部还是this->speed this->stop()
但是对象一定要活着，因为[this]意味着里面保存了this的地址
如果对象被销毁了之后再调用lambda，那么this就会变成无效地址，需要管理生命周期









*/