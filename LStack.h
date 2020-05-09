//
// Seng1120: Assignment 2
// File: LStack.h
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.
//
// Represents a rod
//  Contains:
//      1.List of Disc
//  Requirement:
//      1.Elements on list need to be increasing in size.
//      2.If addition of larger element on smaller one, error return
// ***Functions***

#ifndef ASSIGNMENT2_FIXED_LSTACK_H
#define ASSIGNMENT2_FIXED_LSTACK_H

#include <iostream>
#include <string>
#include "LinkedList.hpp"

template <typename var_type>
class LStack {
public:
    //Pre-Condition: None
    //
    //Post-Condition: None
    LStack();

    //Pre-Condition: LStackObject
    //
    //Post-Condition: None
    LStack(LStack const &copy);

    //Pre-Condition: None
    //
    //Post-Condition:  None
    ~LStack();

    //Pre-Condition: int size of Disc
    //
    //Post-Condition: bool, was successful--> true
    bool push(int size);

    //Pre-Condition: None
    //
    //Post-Condition: Size of removed disc
    int pop();

    //Pre-Condition: None
    //
    //Post-Condition: Int number of discs
    int size();

    //Pre-Condition: None
    //
    //Post-Condition: Int, size of top disc
    int sizeOfTop();

    //Pre-Condition: int, position of disc
    //
    //Post-Condition: string of disc
    std::string getRodComponent(int pos);

private:
    LinkedList<var_type>* Disc_List;
};

#include "LStack.hpp"

#endif //ASSIGNMENT2_FIXED_LSTACK_H
