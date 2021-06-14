#include<stack>

class MyQueue {
public:
    /** Initialize your data structure here. */
    std::stack<int> in_stack;
    std::stack<int> out_stack;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(out_stack.empty())
        {
            while(!in_stack.empty())
            {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        int temp = out_stack.top();
        out_stack.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if(out_stack.empty())
        {
            while(!in_stack.empty())
            {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        return out_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return out_stack.empty() && in_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */