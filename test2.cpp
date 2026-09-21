#include<iostream>
#include<vector>
double speed = 2.0;
double& ref  = speed; //引用本质上就是给变量换了个名字，两个变量本质一样

int countDangerous(const std::vector<double>& distances);
void Change_Value(double& value )
    {
        value = 100.0;
    }

std::vector<double> data ={1.0,2.0,3.0};//vector类型的数组，数组里面的元素都是double类型的，这个数组名叫data
std::vector<double> distances ={3.5, 0.7, 2.1, 0.4, 5.0};
void printDistances(const std::vector<double>& distances)
{
    for (double distance : distances) //范围for直接省掉了循环数，遍历容器输出单个元素
    {
        std::cout << distance << std::endl;
    }
}

int main()
{
    speed = 0;
    std::cout<<ref<<std::endl;
    Change_Value(ref);
    std::cout<<speed<<std::endl;
    printDistances(data);
    countDangerous(distances);
    return 0;
}

int countDangerous(const std::vector<double>& distances)//危险计算
{   int danger_count=0;
    for(double distance:distances)
    {
        if(distance<1.0)
        {
            danger_count++;
        }

    }
    std::cout<<danger_count<<std::endl;//打印可以在外部打印，或者封装一个打印函数
    return danger_count;
}
//const std::vector<double>& distances  引用原来的 vector，不复制它，但只允许读，不允许通过这个引用修改它

