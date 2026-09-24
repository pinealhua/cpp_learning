/*
继承   在已有类型的基础上，继续增加功能，而不是把已有代码重新复制一遍 

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

protect适合用户不希望直接操作，但是子类可以继续使用

*/

