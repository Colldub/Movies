/*
    Computer Science 2
    Main File

    Collin Worth 11-7-23
*/

#include <iostream>
#include <fstream>
#include "Tree.h"
#include "List.h"
using namespace std;

int main(){

    Tree tr;
    int exit = 0;

    ifstream fData("Movies.txt"); // open file for use
    while(exit == 0){
        cout << " im trying " << endl;
        exit = tr.GetData(fData);
        cout << " finished " << endl;
    }
    fData.close();

    //other things i want to do
    tr.printTree();
    tr.deleteTree();
    
    
    return 0;
}