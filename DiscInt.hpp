//
// Seng1120: Assignment 2
// File: DiscInt.hpp
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.
//
// ***Functions***
// 1.Constructor: DiscInt(int N)
// 2.Destructor: ~DiscInt()
// 3.int getNum() const
// 4.Operator <<
// 5.Operator <
// 6.Operator >

#ifndef ASSIGNMENT2_DISCINT_HPP
#define ASSIGNMENT2_DISCINT_HPP
#include <iostream>

class DiscInt
{
public:
    // Pre-Condition: int N: The number of the disk
    //
    // Post-Condition: None
    DiscInt(int N)
    {
        Num = N;// Assign Parameter
    }

    DiscInt(DiscInt const &copy)
    {
        Num = copy.getSize();
    }
    // Pre-Condition: None
    //
    // Post-Condition: None
    ~DiscInt()
    {
        // No action needed
    }
    // Pre-Condition: None
    //
    // Post-Condition: Integer of the Disk object
    int getSize() const
    {
        return Num;
    }

    int getData() const
    {
        return Num;
    }

private:
    int Num;    // Disk number should always remain constant during the game
};

std::ostream& operator << (std::ostream& out, DiscInt& Disk)
{
    out << Disk.getSize();
    return out;
}

bool operator < (DiscInt& Disc1, DiscInt& Disc2)
{
    if(Disc1.getSize() < Disc2.getSize())
    {
        return true;
    }
    return false;
}

bool operator > (DiscInt& Disc1, DiscInt& Disc2)
{
    if(Disc1.getSize() == Disc2.getSize())
        return false;
    return !(Disc1 < Disc2);
}
#endif //ASSIGNMENT2_DISCINT_HPP
