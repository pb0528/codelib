#include<vector>

using namespace std;
class Solution34 {
public:
    int BinarySearch(const vector<int>& nums, const int& target)//[begin,middle,end]
    {
        int begin = 0, end = nums.size()-1;
        int middle = 0;
        while(begin <= end)
        {
            middle = begin + (end - begin)/2;
            if(target < nums[middle])
            {
                end = middle-1;
            }
            else 
            if(target > nums[middle])
            {
                begin = middle+1;
            }
            else return middle;
        }
        return -1;
    };
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = BinarySearch(nums,target);
        int len = nums.size();
        if(-1 == pos)
        {
            return {-1,-1};
        }
        else
        {
            int pre = pos;
            int next = pos;
            while(pre > 0)
            {
                if(nums[--pre] != target) break;
            }
            while(next < len)
            {
                if(nums[++next] != target) break;
            }
            return {pre+1,next-1};
        }
    };

    int FindLeftPos(const vector<int>& nums, const int& target) //模型: (begin,end] 
    {
        int begin = 0 , end = nums.size() - 1;
        int middle = 0;
        while(begin < end)
        {
            middle = begin + (end - begin)/2; // 偏左趋近
            if(nums[middle] >= target) end = middle;
            else begin = middle + 1;
        }
        return end;
    }

    int FindRightPos(const vector<int>& nums, const int& target)//模型:[begin,end)
    {
        int begin = 0 , end = nums.size()-1;
        int middle = 0;
        while(begin < end)
        {
            middle = end - (end - begin)/2; //偏右趋近
            if(nums[middle] <= target) begin = middle;
            else end = middle - 1; 
        }
        return begin;
    }
};