#pragma BaseTree_H

#include <string>

namespace cyctronic
{
    template <typename T>
    struct Node
    {
        Node *rightChild;
        Node *leftChild;
        T item;
    };

    template <class T>
    class BaseTree
    {
    public:
        typedef typename T::name newname;
        BaseTree();
        virtual ~BaseTree();
        
        virtual bool addNode(Node<T> node);

    private:
        int floor_num;
        int Tree_pos;
    };
}
