#include"./src/MyQueue.h"
#include"./src/KthLargest.h"
#include"./src/Valid_Anagram_242.h"
#include"./src/541.h"
#include"./src/offer23.h"
#include"./src/151.h"
#include"./src/offer58.h"
#include"./src/BinarySearch.h"
#include"./src/34.h"
#include<iostream>

#define log(x) std::cout<<x<<std::endl

int main()
{
    vector<int> nums({1,2,2,2,3});
    //vector<int> nums = {1};
    Solution34 sol;
    //sol.searchRange(nums, 1);
    //vector<int> reult = {1,2,3};
    log(sol.FindRightPos(nums,2));
    return 0;
}

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int j;
        for(int i = 0, j = 0; i < len;i++)
        {
            if(nums[i] != val) nums[j++] = nums[i];
        }
        return j;
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};