//
// Seng1120: Assignment 2
// File: DiscString.cpp
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.

#include "DiscString.h"

DiscString::DiscString(int N)
{
    for(int i = 0; i < (2*N - 1); i++)
    {
        X_Disk.append("X");
    }
}

DiscString::DiscString(DiscString const &copy)
{
    X_Disk = copy.getData();
}

DiscString::~DiscString()
{
    // No action needed
}

int DiscString::getSize() const
{
    return (int)((X_Disk.size() + 1)/2);
}

std::string DiscString::getData() const
{
    return X_Disk;
}

std::ostream& operator << (std::ostream& out, DiscString& Disk)
{
    out << Disk.getData();
    return out;
}

bool operator < (DiscString& Disc1, DiscString& Disc2)
{
    return Disc1.getSize() < Disc2.getSize();
}

bool operator > (DiscString& Disc1, DiscString& Disc2)
{
    if(Disc1.getSize() == Disc2.getSize())
        return false;
    return !(Disc1 < Disc2);
}