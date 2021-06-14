#include<iostream>
#include<set>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    static bool hasCycle(ListNode *head) {
        ListNode *cur = head;
        std::set<ListNode*> Node_set;
        while(cur)
        {
            if(cur) Node_set.insert(cur);
            cur = cur->next;
            if(cur && *Node_set.find(cur)) return true;
        }
        return false;
    }
};

int main()
{
    std::cout<<"hello world!\n";
    ListNode node1(1);
    ListNode node2(2);
    ListNode* ptr = &node1;
    node1.next = &node2;
    Solution::hasCycle(ptr);
    return 0;
}