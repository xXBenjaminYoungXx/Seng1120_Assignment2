//
// Created by User on 7/04/2020.
//

#include <iostream>
#include "LinkedList.hpp"
#define mx 9
#define mx2 5
using namespace std;

typedef LinkedList<int> var;
int main(){
    int arr[mx] = {1,2,3,4,5,6,7,8,9};
    var listarr[mx2];

    for(int i = 0; i < mx2; i++)
    {
        for(int y = 0; y < mx; y++)
        {
            listarr[i].addToBottom(arr[y]+i);
        }
    }

    for(int i = 0; i < mx2; i++)
    {
        cout << listarr[i];
    }
}