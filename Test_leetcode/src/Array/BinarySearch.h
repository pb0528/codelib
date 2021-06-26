#include<vector>


using namespace std;

class SolutionBinarySearch
{
public:
    int BinarySearch(const vector<int>& nums, const int& target)//{-1,0,3,5,9,12} 默认target 在[begin,end]这个左闭右闭区间,所以使用begin <= end
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
    }

    int BinarySearch2(const vector<int>& nums, const int& target)//{-1,0,3,5,9,12} 默认target 在[begin,end)这个左闭右闭区间,所以使用begin < end 
    {
        int begin = 0, end = nums.size();
        int middle = 0;
        while(begin < end)
        {
            middle = begin + (end - begin)/2;
            if(target < nums[middle])
            {
                end = middle;
            }
            else 
            if(target > nums[middle])
            {
                begin = middle+1;
            }
            else return middle;
        }

        return -1;
    }
};