#include<iostream>

using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct Node{
        int val{0};
        Node* next;
        Node(int val) : val(val),next(nullptr){}
    };
    MyLinkedList() {
        head = new Node(0);
        _size=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if(index >= _size || index < 0) return -1;
        Node* cur = head;
        while(index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* tmp = new Node(val);
        tmp->next = head->next;
        head->next = tmp;
        _size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* preHead = head;
        while(preHead->next != nullptr)
        {
            preHead = preHead->next;
        }
        Node* tmp = new Node(val);
        preHead->next = tmp;
        _size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > _size) {
            return;
        }
        Node* newNode = new Node(val);
        Node* cur = head;
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        Node* cur = head;
        while(index--) {
            cur = cur ->next;
        }
        Node* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    void printLinkedList() {
        Node* cur = head;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    private:
    int _size{0};
    Node* head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */