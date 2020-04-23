//
// Created by User on 7/04/2020.
//

#include <iostream>
#include "DiscInt.hpp"
#include "DiscString.hpp"
#include "TowerHanoi.hpp"
#define mx 9
#define mx2 5
using namespace std;

typedef int var;
int main(){
    TowerHanoi<DiscInt> game(5);
    game.move(1,2);
    game.move(1,3);
    game.move(2,3);
    cout << (game.gamePrint(1,0));
    cout << "Success";
}

