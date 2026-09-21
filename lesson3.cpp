#include <iostream>

int main()
{
    for (int i = 0; i < 10; i++)
    {

        if (i==3)
        {
           continue;
        }
        

        std::cout << "scan: " << i << std::endl;

        if (i==7)
        {
          break;  
        }
        

    }

    return 0;
}