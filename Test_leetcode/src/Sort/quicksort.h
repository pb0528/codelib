#include<vector>
#include<iostream>

namespace Sort
{
    using namespace std;

    //small 始终保存最左侧小于等于目标的值
    int partion(vector<int>& vec, int start, int end)
    {
        int target = (start+end)/2, small = start-1;
        swap(vec[target],vec[end]);
        for(int index=start; index< end; index++)
        {
            if(vec[index] < vec[end])
            {
                small++;
                if(small != index) swap(vec[small],vec[index]);
            }
        }

        ++small;
        swap(vec[small],vec[end]);
        return small;
    }

    int partion_2(vector<int>& vec, int start, int end)
    {
        int target = vec[(start+end)/2];
        int low = start, high = end;
        while(low<high)
        {
            while((vec[high]>=target) && (low<high)) high--;
            swap(vec[high],vec[low]);
            while((vec[low]<=target) && (low<high)) low++;
            swap(vec[low],vec[high]);
        }
        return low;
    }
    void QSort(vector<int>& vec, int start, int end)
    {
        if(start == end) return;
        int index = partion(vec, start, end);
        if(index > start)
        QSort(vec,start,index-1);
        if(index < end)
        QSort(vec,index+1,end);
    }

    void test()
    {
        vector<int> vec = {10,3,7,20,33,8,6,11};
        QSort(vec,0,vec.size()-1);
        for(int i=0; i<vec.size();i++) std::cout<<vec[i]<<" ";
        std::cout<<'\n';
    }
}