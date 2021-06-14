#include<map>
#include<string>

using namespace  std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char,int> s_map,t_map;
        for(auto iter : s)
        {
            s_map[iter]++;
        }
        for(auto iter : t)
        {
            t_map[iter]++;
        }
        return s_map == t_map;
    }
};