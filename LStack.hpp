//
// Seng1120: Assignment 2
// File: LStack.hpp
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

#ifndef ASSIGNMENT2_LSTACK_HPP
#define ASSIGNMENT2_LSTACK_HPP
#include <iostream>
#include "LinkedList.hpp"

template <typename var_type>
class LStack
{
public:
    LStack()
    {
        Disc_List = new LinkedList<var_type>();
    }

    LStack(LStack const &copy)
    {
        Disc_List = new LinkedList<var_type>();
    }

    ~LStack()
    {
        delete(Disc_List);
    }

    bool addToRod(int size)
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

    int removeFromRod()
    {
        if(Disc_List->size() == 0)                          // If No Discs in list
            return 0;                                       //
        int size = (Disc_List->readNode(0)->getSize());     // Get Disc size
        Disc_List->remFromTop();                            // Take Disc off rod
        return size;
    }

    int numOfDiscs()
    {
        return Disc_List->size();
    }

    int sizeOfTopDisc()
    {
        return (Disc_List->readNode(0)->getSize());
    }

    var_type* getDiscInfo(int pos)
    {
        return Disc_List->readNode(pos);
    }
private:
    LinkedList<var_type>* Disc_List;
};

#endif //ASSIGNMENT2_LSTACK_HPP
