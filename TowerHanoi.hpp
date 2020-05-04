

#ifndef ASSIGNMENT2_FIXED_TOWERHANOI_HPP
#define ASSIGNMENT2_FIXED_TOWERHANOI_HPP
#include "TowerHanoi.h"

template <typename var_type>
TowerHanoi<var_type>::TowerHanoi(int discNum)
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

template <typename var_type>
TowerHanoi<var_type>::~TowerHanoi()
{
    delete(Rod_List);
}
/**********************************************************************************************************************/
template <typename var_type>
void TowerHanoi<var_type>::move(int rodFrom, int rodTo)
{                                                                           // Check params
    if((rodFrom > 3) || (rodTo > 3) || (rodFrom < 1) || (rodTo < 1))        // If input rod is non-existent
    {                                                                       //
        std::cout << "***Invalid Rod choice. Choose value 1 2 or 3***" << std::endl;  // Print respective error message
        return;                                                             //
    }                                                                       //
    //
    if(rodFrom == rodTo)                                                    // If the two input rods are equal
    {                                                                       //
        std::cout << "***Invalid Rod choice. Cannot choose same rod***" << std::endl; //
        return;                                                             //
    }                                                                       //
    //
    if((Rod_List->readNode(rodFrom-1)->numOfDiscs() == 0))                  // If rod to take from has no discs
    {                                                                       //
        std::cout << "***Invalid Rod choice. Rod is empty***" << std::endl; // Print respective error message
        return;                                                             //
    }                                                                       //
    // Read rodTo to see if a disc exists, and if so, ensure it's larger
    if(Rod_List->readNode(rodTo - 1)->numOfDiscs() != 0)                    // There is a disc
    {                                                                       // Is that disc larger or smaller
        if(Rod_List->readNode(rodTo-1)->sizeOfTopDisc() < Rod_List->readNode(rodFrom-1)->sizeOfTopDisc())
        {                                                                   // It is smaller, therefore invalid move
            std::cout << "***Invalid Move. Disk on rod is to small***" << std::endl;  //
            return;                                                         //
        }                                                                   //
    }                                                                       //
    Rod_List->readNode(rodTo-1)->addToRod( Rod_List->readNode(rodFrom-1)->removeFromRod() );
    return;                                                                 // Update rods & their added/removed discs
}

template <typename var_type>
bool TowerHanoi<var_type>::checkWin()
{
    if(Rod_List->readNode(2)->numOfDiscs() == gameSize)
        return true;
    return false;
}
/**********************************************************************************************************************/
template <typename var_type>
std::string TowerHanoi<var_type>::gameDiscString(int rod, int y)
{
    if(Rod_List->readNode(rod-1) == NULL)
        return "";

    int numOfDiscs = Rod_List->readNode(rod-1)->numOfDiscs();         // Due to how the Discs are structured and handled in
    // the LinkedLists, the y level may not represent
    if((numOfDiscs < gameSize) && (y < (gameSize - numOfDiscs)))      // The appropriate disc. Because of this, this if statement is needed.
        return "";                                                    // If not all discs are on the rod, y might be out of
    else if((numOfDiscs < gameSize) && (y >= (gameSize - numOfDiscs)))// scope, hence we check to see if y is out of scope,
        y = y-(gameSize-numOfDiscs);                                  // and return empty string
    // If y is in scope, we need to adjust scale
    return Rod_List->readNode(rod-1)->getDiscData(y);                 // Return string data
}

template <typename var_type>
int TowerHanoi<var_type>::getGameSize()
{
    return gameSize;
}

template <typename var_type>
std::ostream& operator << (std::ostream& out, TowerHanoi<var_type>& game)
{
    std::string tempStr;                        // String used to hold data to be modified to then be printed
    int horiz_Length = (2*game.getGameSize()-1);// The number of horizontal characters that is needed to print a rod
    int game_Length = 3*horiz_Length;           // The number of horizontal characters that is needed to print game, excluding spacing characters
    int rodNum = 1;                             // Used to print label numbers

    for(int y = 0; y < game.getGameSize(); y++) // Print rows
    {
        for(int rod = 1; rod != 4; rod++)       // Print coloums
        {
            tempStr = game.gameDiscString(rod,y);

            if(tempStr.size() == 0)             // If true, add whitespace character to maintain alignment
            {
                tempStr = " ";
            }

            while(tempStr.size() < (horiz_Length)) // add white space characters till required length is met
            {
                tempStr.insert(0," ");
                tempStr.insert(tempStr.size()," ");
            }

            if(rod == 1)                        // Add additional whitespace at start to space discs from screen side
                tempStr.insert(0, "  ");
            out << tempStr << " ";              // Add additional whitespace at end of disc to allow space
        }
        out << std::endl;
    }
    // For loop for game base
    for(int x = 0; x < game_Length + 6; x++)    // +6 for spaces between rods/line ends
    {
        out << "-";
    }

    out << std::endl << "  ";                   // Additional whitespace for spacing

    for(int x = 1; x < game_Length + 5; x++)    // For loop for numbering
    {
        if(x == game.getGameSize() || x == 3*game.getGameSize() || x == 5*game.getGameSize())// Every odd multiple of game_length
        {
            out << rodNum;
            rodNum++;
        } else
            out << " ";
    }

    out << std::endl;

    return out;
}// F end
#endif