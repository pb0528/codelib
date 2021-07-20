#include<stack>
#include<set>

struct node
{
    int i;
    node* next;
};

namespace find_crossover_node
{

    using namespace std;
    node *reverse(node *head)
    {
        node *pre = nullptr;
        node *pivot = head;
        node *next = nullptr;
        while (pivot != nullptr)
        {
            next = pivot->next;
            pivot->next = pre;
            pre = pivot;
            pivot = pivot->next;
        }
        return pre;
    }

    node *find_trail_node(node *head)
    {
        node *pivot = head;
        while (pivot->next != nullptr)
        {
            pivot = pivot->next;
        }
        return pivot;
    }

    node *has_cycle(node *head)
    {
        node *s_pivot = head, *q_pivot = head;
        while (q_pivot != nullptr && s_pivot != nullptr)
        {
            if (q_pivot == s_pivot)
                return q_pivot;
            s_pivot = s_pivot->next;
            if (q_pivot->next != nullptr)
                q_pivot = q_pivot->next->next;
            else
                return nullptr;
        }

        return nullptr;
    }

    node *finde_common_node(node *fir, node *second)
    {
        node *trail = find_trail_node(fir);
        trail->next = second;
        node *meeting = has_cycle(fir);
        if (meeting == nullptr)
            return nullptr;

        int circles = 1;
        node *pivot = meeting;
        while (pivot->next != meeting)
        {
            pivot = pivot->next;
            circles++;
        }

        node *pre = fir, *P_next = fir;
        while (circles > 0)
        {
            pre = pre->next;
            circles--;
        }

        while (pre != P_next)
        {
            pre = pre->next;
            P_next = P_next->next;
        }

        return pre;
    }

    node *finde_common_node_2(node *fir, node *second)
    {
        stack<node*> stack1,stack2;
        while(fir != nullptr) 
        {
            stack1.push(fir);
            fir = fir->next;
        }

        while(second != nullptr)
        {
            stack2.push(second);
            second = second->next;
        }

        if(stack1.top() != stack2.top()) return nullptr;
        while(stack1.top() == stack2.top())
        {
            stack1.pop();
            stack2.pop();
        }

        return stack1.top()->next;
    }

    node *finde_common_node_3(node *fir, node *seconnd)
    {
        set<node*> addr_set;
        while(fir != nullptr)
        {
            addr_set.insert(fir);
            fir = fir->next;
        }

        while(seconnd != nullptr)
        {
            if(addr_set.count(seconnd) != 0) return seconnd;
            seconnd = seconnd->next;
        }

        return nullptr;
    }
} // namespace find_crossover_node
