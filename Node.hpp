//
// Created by Benjamin Young on 7/04/2020.
//

#ifndef LAB7_NODE_HPP
#define LAB7_NODE_HPP

#include <cstddef>

template <typename val_type>
class Node
{
public:
    Node()
    {
        next = NULL;
        prev = NULL;
        data = NULL;
    }

    Node(Node* nNode, Node* pNode, val_type* pData)
    {
        next = nNode;
        prev = pNode;
        data = pData;
    }

    ~Node()
    {
        delete(data);
        data = NULL;
    }

    Node* getN() const
    {
        return next;
    }

    Node* getP() const
    {
        return prev;
    }

    val_type* getD() const
    {
        return data;
    }

    void setN(Node* nNode)
    {
        next = nNode;
    }

    void setP(Node* pNode)
    {
        prev = pNode;
    }

private:
    Node* next;//next node on list
    Node* prev;//previous node on list
    val_type* data;//Once set it cannot change
};

#endif //LAB7_NODE_HPP
