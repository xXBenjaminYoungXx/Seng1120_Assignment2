//
// Seng1120: Assignment 2
// File: Node.h
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.

#ifndef ASSIGNMENT2_FIXED_NODE_H
#define ASSIGNMENT2_FIXED_NODE_H

#include <cstddef>

template <typename val_type>
class Node {
public:
    // Pre-Condition: None
    //
    // Post-Condition: None
    Node();

    // Pre-Condition: Node* to next node, Node* to previous node, and val_type* to data.
    // can accept NULL pointers
    //
    // Post-Condition: None
    Node(Node* nNode, Node* pNode, val_type* pData);

    // Pre-Condition: None
    //
    // Post-Condition: None
    ~Node();

    // Pre-Condition: None
    //
    // Post-Condition: Node* to next node
    Node* getN() const;

    // Pre-Condition: None
    //
    // Post-Condition: Node* to previous node
    Node* getP() const;

    // Pre-Condition: None
    //
    // Post-Condition: val_type* to data
    val_type* getD() const;

    // Pre-Condition: Node* to new next node
    //
    // Post-Condition: None
    void setN(Node* nNode);

    // Pre-Condition: Node* to new previous Node
    //
    // Post-Condition: None
    void setP(Node* pNode);

private:
    Node* next;     //next node on list
    Node* prev;     //previous node on list
    val_type* data; //Once set it cannot change
};

#include "Node.hpp"
#endif //ASSIGNMENT2_FIXED_NODE_H
