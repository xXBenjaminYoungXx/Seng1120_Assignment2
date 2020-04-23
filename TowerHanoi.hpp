//
// Created by User on 23/04/2020.
//

#ifndef ASSIGNMENT2_TOWERHANOI_HPP
#define ASSIGNMENT2_TOWERHANOI_HPP
#include <iostream>
#include "LinkedList.hpp"
#include "LStack.hpp"
using namespace std;

template <typename var_type>
class TowerHanoi
{
public:
    TowerHanoi(int discNum)
    {
        gameSize = discNum;
        Rod_List = new LinkedList< LStack<var_type> >;// Initialize List
        LStack<var_type> Rod3;                        // Create Rod objects
        LStack<var_type> Rod2;                        //
        LStack<var_type> Rod1;                        //
        Rod_List->addToTop(Rod3);                     // Add rod objects to List
        Rod_List->addToTop(Rod2);                     // RodN: Rod_List[N-1]
        Rod_List->addToTop(Rod1);                     //
                                                      //
        for(int i = discNum; i != 0 ; i--)            //
        {                                             //
            Rod_List->readNode(0)->addToRod(i);       // Add Discs to initial rod
        }
    }

    ~TowerHanoi()
    {
        delete(Rod_List);
    }

    void move(int rodFrom, int rodTo)
    {
        if((rodFrom > 3) || (rodTo > 3) || (rodFrom < 1) || (rodTo < 1))      // Check params
        {
            cout << "***Invalid Rod choice. Choose value 1 2 or 3***" << endl;
            return;
        }

        if(rodFrom == rodTo)
        {
            cout << "***Invalid Rod choice. Cannot choose same rod***" << endl;
            return;
        }

        if((Rod_List->readNode(rodFrom-1)->numOfDiscs() == 0))       // Take disc-data from rodFrom
        {                                                            //
            cout << "***Invalid Rod choice. Rod is empty***" << endl;// Issues include empty list
            return;
        }
        // Read rodTo to see if a disc exists, and if so ensure its larger
        if(Rod_List->readNode(rodTo - 1)->numOfDiscs() != 0)// There is a disc
        {
            if(Rod_List->readNode(rodTo-1)->sizeOfTopDisc() < Rod_List->readNode(rodFrom-1)->sizeOfTopDisc())
            {
                cout << "***Invalid Move. Disk on rod is to small***" << endl;
                return;
            }
        }
        // The line below removes Disc from rodFrom and adds to rodTo
        Rod_List->readNode(rodTo-1)->addToRod( Rod_List->readNode(rodFrom-1)->removeFromRod() );
        return;
    }

    string gamePrint(int rod, int y)
    {
        string temp = Rod_List->readNode(rod)->getDiscString(y);
        return temp;
    }

    int getGameSize()
    {
        return gameSize;
    }
private:
    LinkedList< LStack<var_type> >* Rod_List;
    int gameSize;
};

template <typename var_type>
std::ostream& operator << (std::ostream& out, TowerHanoi<var_type>& game)
{
    int rod = 0;
    int strSize;
    int gameSize = game.getGameSize();
    string gameString;
    for(int y = 0; y < gameSize; y++)
    {
        for(int x = 0; x != 3; x++)
        {
            //Get string size to figure out Number of white spaces
            gameString = game.gamePrint(rod, y);
            rod++;
        }
        out << gameString << endl;
    }
    return out;
}// F end
#endif //ASSIGNMENT2_TOWERHANOI_HPP
