//
// Created by User on 2/05/2020.
//

#ifndef ASSIGNMENT2_FIXED_TOWERHANOI_H
#define ASSIGNMENT2_FIXED_TOWERHANOI_H
#include <iostream>
#include "LinkedList.hpp"
#include "LStack.hpp"

template <typename var_type>
class TowerHanoi {
public:
    TowerHanoi(int discNum);

    ~TowerHanoi();
/**********************************************************************************************************************/
    void move(int rodFrom, int rodTo);

    bool checkWin();
/**********************************************************************************************************************/
    std::string gameDiscString(int rod, int y);

    int getGameSize();

private:
    LinkedList< LStack<var_type> >* Rod_List;
    int gameSize;
};

template <typename var_type>
std::ostream& operator << (std::ostream& out, TowerHanoi<var_type>& game);

#include "Towerhanoi.hpp"
#endif //ASSIGNMENT2_FIXED_TOWERHANOI_H
