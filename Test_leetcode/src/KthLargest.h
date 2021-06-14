#include<queue>
#include<vector>
#include<iterator>

using namespace std;
class KthLargest {
public:
    std::priority_queue<int, vector<int>, greater<int>> pri_queue;
    int num;
    KthLargest(int k, vector<int>& nums) {
        num = k;
        for(auto iter : nums)
        {
            add(iter);
        }
    }
    
    int add(int val) {
        pri_queue.push(val);
        while(pri_queue.size() > num) pri_queue.pop();
        return pri_queue.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */