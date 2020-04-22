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
    // Pre-Condition: None
    //
    // Post-Condition: None
    Node()
    {
        next = NULL;
        prev = NULL;
        data = NULL;
    }
    // Pre-Condition: Node* to next node, Node* to previous node, and val_type* to data.
    // can accept NULL pointers
    //
    // Post-Condition: None
    Node(Node* nNode, Node* pNode, val_type* pData)
    {
        next = nNode;
        prev = pNode;
        data = pData;
    }
    // Pre-Condition: None
    //
    // Post-Condition: None
    ~Node()
    {
        delete(data);
        data = NULL;
    }
    // Pre-Condition: None
    //
    // Post-Condition: Node* to next node
    Node* getN() const
    {
        return next;
    }
    // Pre-Condition: None
    //
    // Post-Condition: Node* to previous node
    Node* getP() const
    {
        return prev;
    }
    // Pre-Condition: None
    //
    // Post-Condition: val_type* to data
    val_type* getD() const
    {
        return data;
    }
    // Pre-Condition: Node* to new next node
    //
    // Post-Condition: None
    void setN(Node* nNode)
    {
        next = nNode;
    }
    // Pre-Condition: Node* to new previous Node
    //
    // Post-Condition: None
    void setP(Node* pNode)
    {
        prev = pNode;
    }

private:
    Node* next;     //next node on list
    Node* prev;     //previous node on list
    val_type* data; //Once set it cannot change
};

#endif //LAB7_NODE_HPP
