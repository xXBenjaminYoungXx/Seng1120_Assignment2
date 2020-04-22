//
// Created by User on 7/04/2020.
//

#include <iostream>
#include "LinkedList.hpp"
#define mx 9
#define mx2 5
using namespace std;

typedef int var;
int main(){
    int arr[mx] = {1,2,3,4,5,6,7,8,9};
    var listarr[mx2];
    LinkedList<var> List1;
    List1.setListTo(arr, 2);
    cout << List1;
    List1.addAt(arr[7],1);
    cout << List1;
    List1.empty();
    cout << List1;
}