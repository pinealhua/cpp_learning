/*   namespace 运行空间

std::就是运行空间
假如说两个运行文件都写了一个stop函数
void stop()
{
    std::cout << "Robot stop" << std::endl;
}

void stop()
{
    std::cout << "Car stop" << std::endl;
}
如果在主程序调用stop函数，那么主程序肯定不知道该调用哪个函数
所以需要命名空间进行划分区域
namespace robot
{
    void stop()
    {
        std::cout << "Robot stop" << std::endl;
    }
}
namespace car
{
    void stop()
    {
        std::cout << "Car stop" << std::endl;
    }
}
    这个时候调用
robot::stop();
car::stop();     就完全不会冲突

::就是去某个命名空间（作用域）找东西  std::cout就是去 std 命名空间里找 cout
std 就是 C++ 标准库使用的命名空间

namespace可以包住class
namespace rm
{
class Robot
{
public:
    void stop()
    {
    }
};
}
外面创建对象 rm::Robot robot; 在rm命名空间找到Robot类型
同样的namespace可以进行嵌套
namespace sensor_msgs
{
    namespace msg
    {
        class LaserScan
        {
        };
    }
}
sensor_msgs::msg::LaserScan

namespace和class很像，里面也能包含很多东西，但是本质不一样。
class是定义类型，创建Robot robot1   但是namespace不是类型，所以不能rm rm1

namespace在不同的资源文件可以打开，它们都在全局作用域声明了同名的 namespace rm。不是因为 .cpp include 了 .hpp
namespace支持在不同的地方持续添加
namespace rm
{
    // 放一点
}

namespace rm
{
    // 再放一点
}

namespace rm
{
    // 继续放
}
这都是重新打开同一个命名空间
但是为什么需要hpp，因为hpp里面定义了一个class，需要把类定义提供给cpp文件。    

还有一个限定条件就是 同名还必须处于同一个外层作用域
namespace test
{
    namespace rm
    {
    }
}
这个是::test::rm，和::rm不是同一个
就像文件夹路径一样，就算最后一个文件夹名字相同，但是肯定不是同一个文件夹
普通具名 namespace 的身份由它的完整作用域路径决定。#include 不负责让两个 namespace “变成同一个”；
include 只是让当前源文件看到里面声明/定义过的名字

*/