/*
map和unodered_map
对于一个std::vector<double> distances;来说
寻找一个特定元素的时候，只能通过下标进行寻找
distances[0] distances[1] 这样寻找
但是由于可能有不同的数据来源，需要清晰去看每个数据来源对应的数据是多少
可以用std::map 进行区分

#include <map>
#include <string>

std::map<std::string, double> distances;


std::map<
    std::string,
    double
>
这两个参数分别表示key的类型和value的类型
所以这个就可以读成 key是string，value是double的map
就可以写成
distances["front"] = 1.2;
distances["left"] = 0.8;
distances["right"] = 2.1;
访问的时候就是 std::cout << distances["front"]; 输出1.2

map和普通的vector相比
std::vector<double> distances = {1.2, 0.8, 2.1};
std::cout << distances[0];  你得知道0代表的是front

std::map<std::string, double> distances;
distances["front"] = 1.2;   直接就知道front的数据是1.2

所以说vector就是按位置找，map就是按key值找

当然map不一定只能用string当key
std::map<int, double> data;
std::map<double, double> data; 都是完全可以的


遍历map
std::map<std::string, double> distances = {
    {"front", 1.2},
    {"left", 0.8},
    {"right", 2.1}
};
遍历
for (const auto& item : distances)
{
    std::cout << item.first
              << ": "
              << item.second
              << std::endl;
}

这里的item.first 就是key  item.second就是value
所以说输出的就是
front: 1.2
left: 0.8
right: 2.1

还可以写成
for (const auto& [name, distance] : distances)
{
    std::cout << name
              << ": "
              << distance
              << std::endl;
}

[name, distance]这里不是lambda的捕获列表，他叫结构化绑定
就是把map里面这一堆数据拆成两个变量
可以读成遍历每一对数据，把 key 叫 name，value 叫 distance。

如果你想查找某个key是否存在
if (distances["front"] ...) 但是如果原来不存在，那么[]就有可能创建一个默认值
只是查找存不存在，就是
auto it = distances.find("back");

if (it != distances.end())
{
    std::cout << "found" << std::endl;
}
使用.find() 和 .end()

find就是去找这个back，如果没找到，就返回.end()


std::unordered_map<std::string,
                   std::shared_ptr<Robot>> robots;

表示robots 是一个 unordered_map，key 是 std::string，value 是 std::shared_ptr<Robot>

比如说robots["sentry"] 拿到的是std::shared_ptr<Robot>
所以说还能继续robots["sentry"]->stop(); 调用Robot这个类里面的东西

*/