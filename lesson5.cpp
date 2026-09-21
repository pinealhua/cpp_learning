#include<iostream>
#include<vector>

bool isDangerous(double distance)
    {
        
        return distance<1.0;
    }

std::vector<double> distances =
{
    3.5, 0.7, 2.1, 0.4, 5.0
};

int main()
    {
        int danger_count;
    for(int i=0;i<distances.size();i++)    
      { if(isDangerous(distances[i]))
        {
            std::cout << "scan " << i <<" danger" << std::endl;
            danger_count++;
        }
        else
       { 
        std::cout << "scan " << i <<" safe" << std::endl;
        }
    }
    std::cout << danger_count << std::endl;
        
     return 0;
    }