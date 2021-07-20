#include<iostream>
#include<chrono>

using namespace std;
int main()
{
    std::cout<<"hello world! \n";

    chrono::system_clock::duration d = chrono::system_clock::now().time_since_epoch();
    chrono::microseconds mic = chrono::duration_cast<chrono::microseconds>(d);

    std::cout<<"time point: ( " << mic.count() << " )" <<std::endl;

    
    return 0;
}