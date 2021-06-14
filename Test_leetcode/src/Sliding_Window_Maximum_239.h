#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

//解题思路: 维护一个双端队列，该队列始终保持最大值在最左边,保证每一个值插入滑动窗口时最左端都是最大值
/**
 * 例子：[-7,-8,7,5,7,1,6,0] 4
 * [-7]
 * [-7,-8]
 * [ , ,7]
 * [-7,-8,7,5][ , ,7,5] 最大值7
 * [-8,7,5,7] [7,7]  最大值7
 * [7,5,7,1] [7,7,1] 最大值7
 * [5,7,1,6] [7,6] 最大值7
 * [7,1,6,0] [7,6] 最大值7
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()) return vector<int>();
         deque<int> slideWindow;
         vector<int> result;
         for(int i = 0; i < nums.size(); ++i)
         {
            //如果超出k滑动窗口，则删除第一个数
            if(!slideWindow.empty() && (i-slideWindow.front()) >= k) slideWindow.pop_front();
            //插入每一个元素之前都保证该滑动窗口左侧没有比此元素小的值
            while(!slideWindow.empty() && (nums[i] > nums[slideWindow.back()])) slideWindow.pop_back();
            //插入元素
            slideWindow.push_back(i);
            //索引大于窗口值时放入结果集
            if(i >= k-1) result.push_back(nums[slideWindow.front()]);
         }
         return result;
    }
};