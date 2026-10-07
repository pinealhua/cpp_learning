/*
模板
核心思想就是写一次通用代码，让编译器根据具体类型生成对应版本
比如说写一个比较大小的函数，只处理int类型，那函数类型得是int型
int maxValue(int a, int b)
{
    return a > b ? a : b;
}
那如果又要处理double类型的变量，又得重写一个函数
double maxValue(double a, double b)
{
    return a > b ? a : b;
}
再处理float类型
float maxValue(float a, float b)
{
    return a > b ? a : b;
}
其实函数实现的逻辑一样，只不过类型不一样
使用模板就可以把类型本身也当作一个参数

template<typename T>
T maxValue(T a, T b)
{
    return a > b ? a : b;
}

template<typename T>的意思就是 我先定义类型一个占位符T，具体是什么类型以后再说
T maxValue(T a, T b)  这里都是同一个类型

当你要调用int类型函数的时候，就直接maxValue<int>(3, 5);
这时候 T = int
要使用double类型函数的时候maxValue<double>(2.5, 3.8);

template<typename T>
这里的T没有特殊含义，就是个占位符 当然可以随便替换
template<typename Type>
template<typename apple>这些都是可以的

现在再看std::vector<double> distances;
template<typename T>
class vector
{
    // 内部存很多 T
};

vector就是个类模板
vector把 T 指定成 double 得到“装 double 的 vector 类型”
所以说 std::vector<double>才是一个完整类型

还有std::shared_ptr<Robot>
和vector一样，概念上也可以理解成
template<typename T>
class shared_ptr
{
    // 管理一个 T 类型对象
};

std::make_shared<Robot>() 稍微有点区别
概念上类似，都是
template<typename T>
std::shared_ptr<T> makeSomething()
{
    ...
}
所以std::make_shared<Robot>() 就是 T=Robot 创建Robot 返回shared_ptr<Robot>
auto robot = std::make_shared<Robot>();  右边就是返回shared_ptr<Robot>

至于std::make_shared<Robot>(3.0);
同时出现Robot和3.0 肯定不冲突
<Robot>是模板类型参数，告诉编译器要创建一个Robot类型
(3.0)是普通运行时函数的参数，会继续传给Robot(double initial_speed)

模板也可以有多个类型参数
template<typename T1, typename T2>
class Pair
{
};
就可以pair<int,double> 表示T1 = int ，  T2 = double

模板要写在hpp里面，因为编译器在使用某个模板的时候，需要看到模板的完整实现才能生成










*/