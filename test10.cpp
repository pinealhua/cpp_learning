/*

auto自动类型推导
auto count = 5;
auto speed = 2.5;
auto motor_on = true;
auto name = std::string("sentry");
编译器，你根据右边的初始化表达式，帮我推断这里应该是什么类型
编译完成之后 count还是int类型，speed还是double类型 motor_on还是bool类型

auto必须要有东西给他推导   auto speed = 2.5;这个可以   auto speed;不行  所以说右边的很重要

auto在范围for里面很常见
std::vector<double> distances = {1.0, 2.0, 3.0};
for (auto distance : distances)
{
    std::cout << distance << std::endl;
}
编译器知道distances是vector<double>，所以说就知道auto distance是double distance

for (const auto& point : points)
const只读 auto自动识别数据类型 &直接引用
对于每一个points元素，直接识别类型然后引用且不改变原元素

std::vector<Robot> robots; 
for (const auto& robot : robots)
这里的auto就是Robot

对于返回某个很长类型的函数来说，没有auto的时候可能需要SomeVeryLongNamespace::SomeVeryLongType value = function();
对于返回类型已经确定的来说，auto value = function();就可以了。function返回什么类型，value就是什么类型

auto不是动态类型，不能前面已经auto speed = 3.0 后面又说speed = "hello";

auto* 也可以推导指针 比如说Robot robot； Robot* ptr =&robot
也可以auto* ptr = &robot;   甚至auto ptr = &robot; 这里也能推出来是Robot*

auto node = rclcpp::Node::make_shared("my_node");  这里rclcpp::和Node::都要保留，auto只是告诉你这个变量是什么类型，但是他不会帮你找这个变量在哪里


*/