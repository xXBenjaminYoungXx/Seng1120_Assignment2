//
// Seng1120: Assignment 2
// File: LStack.hpp
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.

#ifndef ASSIGNMENT2_FIXED_LSTACK_HPP
#define ASSIGNMENT2_FIXED_LSTACK_HPP

#include "LStack.h"

template <typename var_type>
LStack<var_type>::LStack()
{
    Disc_List = new LinkedList<var_type>();
}

template <typename var_type>
LStack<var_type>::LStack(LStack const &copy)
{
Disc_List = new LinkedList<var_type>();
}

template <typename var_type>
LStack<var_type>::~LStack()
{
    delete(Disc_List);
}

template <typename var_type>
bool LStack<var_type>::push(int size)
{
    if(Disc_List->size() == 0)                          // If no discs are currently on rod
    {
    }else if(Disc_List->readNode(0)->getSize() < size)  // If top disc is smaller than moved disc
    {
        return false;
    }
    var_type to_add(size);                              // Create disc on stack as LInkedList Class will copy on heap
    Disc_List->addToTop(to_add);                        // Add to list
    return true;
}

template <typename var_type>
int LStack<var_type>::pop()
{
    if(Disc_List->size() == 0)                          // If No Discs in list
        return 0;                                       //
    int size = (Disc_List->readNode(0)->getSize());     // Get Disc size
    Disc_List->remFromTop();                            // Take Disc off rod
    return size;
}

template <typename var_type>
int LStack<var_type>::size()
{
    return Disc_List->size();
}

template <typename var_type>
int LStack<var_type>::sizeOfTop()
{
    if(Disc_List->readNode(0) == NULL)
        return 0;
    return (Disc_List->readNode(0)->getSize());
}

/**********************************************************************************************************************/
/*Used for print operations*/
template <typename var_type>
std::string LStack<var_type>::getRodComponent(int pos)
{
    if(Disc_List->readNode(pos) == NULL)
        return "";
    return Disc_List->readNode(pos)->getData();
}

#endif