//
// Seng1120: Assignment 2
// File: DiscString.h
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.
//
// ***Functions***
// 1.Constructor: DiscString(string N)
// 2.Constructor: DiscString(DiscString& Disc)
// 2.Destructor: ~DiscString()
// 3.int getSize() const
// 4.String getData() const
// 5.Operator <<
// 6.Operator <
// 7.Operator >

#ifndef ASSIGNMENT2_FIXED_DISCSTRING_H
#define ASSIGNMENT2_FIXED_DISCSTRING_H
#include <iostream>
#include <string>

class DiscString {
public:
    // Pre-Condition: int N: The number of the disk
    //
    // Post-Condition: None
    DiscString(int N);

    // Pre-Condition: DiscString object to copy
    //
    // Post-Condition: None
    DiscString(DiscString const &copy);

    // Pre-Condition: None
    //
    // Post-Condition: None
    ~DiscString();

    // Pre-Condition: None
    //
    // Post-Condition: Integer representing the Disk size
    int getSize() const;

    // Pre-Condition: None
    //
    // Post-Condition: Integer of the Disk object
    std::string getData() const;

private:
    std::string X_Disk;    // Disk String should always remain constant during the game
};

// Pre-Condition: ostream object << with DiscString object
//
// Post-Condition: ostream object with int of DiscString object
std::ostream& operator << (std::ostream& out, DiscString& Disk);

// Pre-Condition: DiscString object < with DiscString object
//
// Post-Condition: Bool according to relative size
bool operator < (DiscString& Disc1, DiscString& Disc2);

// Pre-Condition: DiscString object > with DiscString object
//
// Post-Condition: Bool according to relative size
bool operator > (DiscString& Disc1, DiscString& Disc2);

#endif //ASSIGNMENT2_FIXED_DISCSTRING_H
