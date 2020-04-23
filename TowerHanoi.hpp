//
// Created by User on 23/04/2020.
//

#ifndef ASSIGNMENT2_TOWERHANOI_HPP
#define ASSIGNMENT2_TOWERHANOI_HPP
#include <iostream>
#include "LinkedList.hpp"
#include "LStack.hpp"

template <typename var_type>
class TowerHanoi
{
public:
    TowerHanoi(int discNum)
    {
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
        cout << "Success" << endl;
    }

    ~TowerHanoi()
    {
        delete(Rod_List);
    }

    /*void move(int rodFrom, int rodTo)
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

        if((Rod_List->readNode(rodFrom-1)->numOfDiscs() == 0))         // Take disc-data from rodFrom
        {                                                            //
            cout << "***Invalid Rod choice. Rod is empty***" << endl;// Issues include empty list
        }


        // Read rodTo to see if a disc exists, and if so ensure its larger
        if(!(Rod_List->readNode(rodTo-1)->numOfDiscs() == 0))// There is a disc
        {

        }

        int disc_removed_Size;
        disc_removed_Size = Rod_List->readNode(rodFrom-1)->removeFromRod();


    }
*/
private:
    LinkedList< LStack<var_type> >* Rod_List;
};
#endif //ASSIGNMENT2_TOWERHANOI_HPP
