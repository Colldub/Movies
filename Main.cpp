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

    ifstream fData("Movies.txt"); // open file for use
    for(int i = 0; i < 2; i ++){
        tr.GetData(fData);
    }
    fData.close();

    tr.printTree();
    tr.deleteTree();
    
    
    return 0;
}