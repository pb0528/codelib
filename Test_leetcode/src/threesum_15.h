#include<vector>
#include<map>
#include<set>
using namespace std;
class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return vector<vector<int>>();
        vector<vector<int>> result;
        multimap<int,int> index_map;
        set<int> bool_vec;
        for(int i = 0; i < nums.size(); i++)
        {
            //bool_vec[i] = 0;
            index_map.insert(make_pair(nums[i],i));
        } 
        for(int x = 0; x < nums.size(); x++)
        {
            for(int y = x+1; y < nums.size(); y++)
            {
                int z = -(nums[x] + nums[y]);
                for(auto iter = index_map.equal_range(z).first; iter != index_map.equal_range(z).second; ++iter)
                {
                    if (bool_vec.count(x + y + iter->second) != 0)
                        break;
                    bool_vec.insert(x + y + iter->second);
                    result.emplace_back(vector<int>({nums[x], nums[y], z}));
                }
            }
        }
        return result;
    }
};