/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        //记录尾指针
        while(cur != nullptr && num < (n-1))
        {
            num++;
            cur = cur->next;
        }
        //创建头指针
        pre = head;
        ListNode* _pre = nullptr;
        while(cur->next != nullptr)
        {
            _pre = pre;
            pre = pre->next;
            cur = cur->next;
        }
        //如果先序指针是空指针，说明是删除头节点
        if(_pre == nullptr) 
        {
            head = pre->next;
        }
        else _pre->next = pre->next;
        delete pre;
        return head;
    }
};

class solution19_2
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int num = 0;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* cur = pre;
        while(cur->next != nullptr && num < n)
        {
            cur = cur->next;
            num++;
        }
        ListNode* del = pre->next;
        ListNode* _del = pre;
        while(cur!=nullptr)
        {
            _del = _del->next;
            del = del->next;
            cur = cur->next;
        }

        _del->next = del->next;
        delete del;
        return pre->next;
    }
};

ListNode* Reverse_List(ListNode* head)
{
    ListNode* pre = nullptr;
    ListNode* pivot = head;
    ListNode* next = nullptr;

    while(pivot != nullptr)
    {
        next = pivot->next;
        pivot->next = pre;
        pre = pivot;
        pivot = next;
    }

    return pre;
}

ListNode* Reverse(ListNode* pivot, ListNode* pre);
ListNode* Reverse_List_recursion(ListNode* head)
{
    if(head == nullptr) return nullptr;
    ListNode* pre = nullptr;
    Reverse(head, pre);
}

ListNode* Reverse(ListNode* pivot, ListNode* pre)
{
    if(pivot == nullptr) return pre;
    ListNode* next = pivot->next;
    pivot->next = pre;
    pre = pivot;
    Reverse(next, pre);
}

