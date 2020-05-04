//
// Seng1120: Assignment 2
// File: DiscInt.h
// Author: Benjamin Yong
// Student ID: C3330653
// Email: BenjaminYoung7198@gmail.com
// Date: 22/04/2020.
//
// ***Functions***
// 1.Constructor: DiscInt(int N)
// 2.Constructor: DiscInt(DiscInt& Disc)
// 3.Destructor: ~DiscInt()
// 4.int getSize()
// 5.string getData() const
// 6.Operator <<
// 7.Operator <
// 8.Operator >

#ifndef ASSIGNMENT2_FIXED_DISCINT_H
#define ASSIGNMENT2_FIXED_DISCINT_H

#include <iostream>
#include <string>

class DiscInt {
public:
    // Pre-Condition: int N: The number of the disk
    //
    // Post-Condition: None
    DiscInt(int N);

    // Pre-Condition: Object to copy
    //
    // Post-Condition: None
    DiscInt(DiscInt const &copy);

    // Pre-Condition: None
    //
    // Post-Condition: None
    ~DiscInt();

    // Pre-Condition: None
    //
    // Post-Condition: Integer of the Disk object
    int getSize() const;

    // Pre-Condition: None
    //
    // Post-Condition: String representing number
    std::string getData() const;

private:
    int Num;// Disk number should always remain constant during the game
};

// Pre-Condition: ostream object << with DiscInt object
//
// Post-Condition: ostream object with int of DiscInt object
std::ostream& operator << (std::ostream& out, DiscInt& Disk);

// Pre-Condition: DiscInt object < with DiscInt object
//
// Post-Condition: Bool according to relative size
bool operator < (DiscInt& Disc1, DiscInt& Disc2);

// Pre-Condition: DiscInt object > with DiscInt object
//
// Post-Condition: Bool according to relative size
bool operator > (DiscInt& Disc1, DiscInt& Disc2);

#endif //ASSIGNMENT2_FIXED_DISCINT_H