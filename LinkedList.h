//
// Seng1120: Assignment 2
// File: LinkedList.h
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.
//
// ***Functions***
// 1.LinkedList Constructors
// 2.Destructor
// 3.setListTo(var_type array, int size)
// 4.empty()
// 5.addToTop(var_type*)
// 6.remFromTop()
// 7.addToBottom(var_type*)
// 8.remFromBottom()
// 9.addAt(Node*, int pos)
// 10.data* readNode(int pos)
// 11.int size()
// 12.+= concatenate
// 13.[i] index at pos i
// 14.= L2: setListTo(L2);
// 15.<< print List
// 16. == return bool if linked list is equal to the other
// 17. != !(==)
//
// ***Functions to add***
// 1. remAt(i()--> removed node at i shifting nodes up

#ifndef ASSIGNMENT2_FIXED_LINKEDLIST_H
#define ASSIGNMENT2_FIXED_LINKEDLIST_H

#include "Node.hpp"
#include <iostream>

template <typename var_type>
class LinkedList {
public:
/**********************************************************************************************************************/
    // Pre-Condition: None
    //
    // Post-Condition: None
    LinkedList();
/**********************************************************************************************************************/
    // Pre-Condition: dataArray of var_type, and integer of array size
    //
    // Post-Condition: None
    LinkedList(const var_type dataList[], int size);
/**********************************************************************************************************************/
    // Pre-Condition: None
    //
    // Post-Condition: None
    ~LinkedList();

/**********************************************************************************************************************/
    // Pre-Condition: dataArray of var_type, and integer of array size
    //
    // Post-Condition: None
    //
    // Note: Can be used to empty List
    void setListTo(const var_type dataList[], int size);

/**********************************************************************************************************************/
    // Pre-Condition: None
    //
    // Post-Condition: Node
    //
    // Note: Uses setListTo(NULL, 0) to empty list
    void empty();

/**********************************************************************************************************************/
    // Pre-Condition: Reference to var_type
    //
    // Post-Condition: None
    void addToTop(const var_type& temp);

/**********************************************************************************************************************/
    // Pre-Condition: None
    //
    // Post-Condition: None
    void remFromTop();

/**********************************************************************************************************************/
    // Pre-Condition: None
    //
    // Post-Condition: None
    void addToBottom(const var_type& temp);

/**********************************************************************************************************************/
    // Pre-Condition: None
    //
    // Post-Condition: None
    void remFromBottom();

/**********************************************************************************************************************/
    // Pre-Condition: reference to var_type
    //
    // Post-Condition: int of position in array
    void addAt(const var_type& temp, int pos);

/**********************************************************************************************************************/
    // Pre-Condition: int position of List
    //
    // Post-Condition: var_type* to data
    var_type* readNode(int pos);

/**********************************************************************************************************************/
    // Pre-Condition: None
    //
    // Post-Condition: int of List size
    int size();

/**********************************************************************************************************************/
    // Pre-Condition: LinkedList<var_type> Reference
    //
    // Post-Condition: this.List concatenated with L2 as a reference
    LinkedList<var_type>& operator += (LinkedList<var_type>& L2);

/**********************************************************************************************************************/
    // Pre-Condition: int position
    //
    // Post-Condition: var_type& reference
    var_type& operator [] (int pos);

/**********************************************************************************************************************/
    // Pre-Condition: LinkedList<var_type> Reference
    //
    // Post-Condition: LinkedList<var_type > Reference
    LinkedList<var_type>& operator = (LinkedList<var_type>& L2);

/**********************************************************************************************************************/
private:
    Node<var_type>* head;
    Node<var_type>* tail;
    Node<var_type>* iterator;
};

// Pre-Condition: ostream object << LinkedList<var_type>
//
// Post-Condition: Prints data to screen
template <typename var_type>
std::ostream& operator << (std::ostream& out, LinkedList<var_type>& list);

// Pre-Condition: LinkedList<var_type> == LinkedList<var_type>
//
// Post-Condition: Returns bool true if equal
template <typename var_type>
bool operator == (LinkedList<var_type>& L1, LinkedList<var_type>& L2);

// Pre-Condition: LinkedList<var_type> == LinkedList<var_type>
//
// Post-Condition: Returns bool true if not-equal
template <typename var_type>
bool operator != (LinkedList<var_type>& L1, LinkedList<var_type>& L2);

#include "LinkedList.hpp"
#endif //ASSIGNMENT2_FIXED_LINKEDLIST_H
