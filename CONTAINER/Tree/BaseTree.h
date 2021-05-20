#pragma BaseTree_H

#include<string>

template<typename T>
struct Node
{
    Node* rightChild;
    Node* leftChild;
    T   item;
};

template<typename T>
class BaseTree
{
    typedef typename T::name  newname;
    explict BaseTree();
    virtual ~BaseTree();

private:
    int floor_num;
    int Tree_pos;
};