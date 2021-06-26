#include<unordered_map>
#include<string>
#include<iterator>
#include<iostream>

using namespace std;
int main()
{
    unordered_map<string,string> s_map;
    s_map["hello"] = "dear";
    s_map["computer"] = "is not the sum";
    for(auto iter = s_map.begin(); iter != s_map.end(); iter++)
    {
        std::cout<<iter->first<<"   "<<iter->second<<std::endl;
    }
    return 0;
}