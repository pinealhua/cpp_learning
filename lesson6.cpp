#include <iostream>

int main()
{
    double speed = 2.0;

    double& ref = speed;//引用不是副本，而是原变量的另一个名字

    ref = 5.0;

    std::cout << speed << std::endl;

    return 0;
}