#include <iostream>
#include<vector>
int danger_count = 0;
std::vector<double> distances = {3.5, 0.7, 2.1, 0.4, 5.0};
int main()
{
    for(int i=0;i<distances.size();i++ )
        {
            if(distances[i]>1.0f)
            std::cout << "Scan: "<<i<<"  "<<distances[i] <<"--safe"<< std::endl;
            else
            {
                std::cout << "Scan: "<<i<<"  "<<distances[i] <<"--danger"<< std::endl;
                danger_count++;
            } 
        }
        std::cout << "danger count:"<<danger_count << std::endl;
    return 0;
}
