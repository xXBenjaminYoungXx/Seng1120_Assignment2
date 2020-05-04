//
// Seng1120: Assignment 2
// File: Node.hpp
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.

#ifndef ASSIGNMENT2_FIXED_NODE_HPP
#define ASSIGNMENT2_FIXED_NODE_HPP

#include "Node.h"

template <typename var_type>
Node<var_type>::Node()
{
    next = NULL;
    prev = NULL;
    data = NULL;
}

template <typename var_type>
Node<var_type>::Node(Node* nNode, Node* pNode, var_type* pData)
{
    next = nNode;
    prev = pNode;
    data = pData;
}

template <typename var_type>
Node<var_type>::~Node()
{
    delete(data);
    data = NULL;
}

template <typename var_type>
Node<var_type>* Node<var_type>::getN() const
{
    return next;
}

template <typename var_type>
Node<var_type>* Node<var_type>::getP() const
{
    return prev;
}

template <typename var_type>
var_type* Node<var_type>::getD() const
{
    return data;
}

template <typename var_type>
void Node<var_type>::setN(Node* nNode)
{
    next = nNode;
}

template <typename var_type>
void Node<var_type>::setP(Node* pNode)
{
    prev = pNode;
}

#endif
