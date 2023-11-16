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
    int test = 0;
    while(exit == 0){
        exit = tr.GetData(fData);
    }
    fData.close();
    //other things i want to do
    //Display all movies in the tree (only the titles!).
    tr.DisplayTitles();
    //Display all actors of a given movie in the tree: Bullitt, Man of the Year, The April Fools and two others of your choice.
    //Display all movies of a given actor: Tom Cruise, Carrie Fisher, Roger Moore, and two others of your choice.
    //Display all movies released in 1970 and one other year of your choice.
    //tr.printTree();
    tr.deleteTree();
    
    
    return 0;
}