//
// Seng1120: Assignment 2
// File: DiscString.hpp
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.
//
// ***Functions***
// 1.Constructor: DiscString(string N)
// 2.Destructor: ~DiscString()
// 3.string getString() const
// 4.int getStringSize() const
// 5.Operator <<
// 6.Operator <
// 7.Operator >

#ifndef ASSIGNMENT2_DISCSTRING_HPP
#define ASSIGNMENT2_DISCSTRING_HPP
#include <iostream>
#include <string>
//using namespace std;

class DiscString
{
public:
    // Pre-Condition: int N: The number of the disk
    //
    // Post-Condition: None
    DiscString(int N)
    {
        for(int i = 0; i < (2*N - 1); i++)
        {
            X_Disk.append("X");
        }
    }

    DiscString(DiscString const &copy)
    {
        X_Disk = copy.getData();
    }

    // Pre-Condition: None
    //
    // Post-Condition: None
    ~DiscString()
    {
        // No action needed
    }
    // Pre-Condition: None
    //
    // Post-Condition: Integer representing the Disk size
    int getSize() const
    {
        return (int)((X_Disk.size() + 1)/2);
    }
    // Pre-Condition: None
    //
    // Post-Condition: Integer of the Disk object
    std::string getData() const
    {
        return X_Disk;
    }

private:
    std::string X_Disk;    // Disk number should always remain constant during the game
};

std::ostream& operator << (std::ostream& out, DiscString& Disk)
{
    out << Disk.getData();
    return out;
}

bool operator < (DiscString& Disc1, DiscString& Disc2)
{
    if(Disc1.getSize() < Disc2.getSize())
    {
        return true;
    }
    return false;
}

bool operator > (DiscString& Disc1, DiscString& Disc2)
{
    if(Disc1.getSize() == Disc2.getSize())
        return false;
    return !(Disc1 < Disc2);
}
#endif //ASSIGNMENT2_DISCSTRING_HPP
