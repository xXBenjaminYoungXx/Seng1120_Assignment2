//
// Seng1120: Assignment 2
// File: DiscInt.cpp
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.

#include "DiscInt.h"

DiscInt::DiscInt(int N)
{
    Num = N;// Assign Parameter
}

DiscInt::DiscInt(DiscInt const &copy)
{
    Num = copy.getSize();
}

DiscInt::~DiscInt()
{
    // No action needed
}

int DiscInt::getSize() const
{
    return Num;
}

std::string DiscInt::getData() const
{
    std::string to_return;
    switch(Num) {
        case 1:
            to_return = "1";
            break;
        case 2:
            to_return = "2";
            break;
        case 3:
            to_return = "3";
            break;
        case 4:
            to_return = "4";
            break;
        case 5:
            to_return = "5";
            break;
    }
    return to_return;
}

std::ostream& operator << (std::ostream& out, DiscInt& Disk)
{
    out << Disk.getSize();
    return out;
}

bool operator < (DiscInt& Disc1, DiscInt& Disc2)
{
    return Disc1.getSize() < Disc2.getSize();
}

bool operator > (DiscInt& Disc1, DiscInt& Disc2)
{
    if(Disc1.getSize() == Disc2.getSize())
        return false;
    return !(Disc1 < Disc2);
}