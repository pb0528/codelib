#include<iostream>
#include<vector>
#include"./src/test.h"


using namespace std;

#define log(x) std::cout<<x<<std::endl

int main()
{
    using namespace sol;
    soulution sole;
    vector<int> rec = {1,2,3,4,5,6,10};
    vector<int> rec2 = {3,4,10,2};
    vector<int> rec3 = {3,10,20,40,100};
    cout<< sole.findSmallestComm(rec,rec2,rec3) <<endl;

    return 0;
}
