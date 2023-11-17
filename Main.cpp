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
    //tr.DisplayTitles();
    //Display all actors of a given movie in the tree: Bullitt, Man of the Year, The April Fools and two others of your choice.
    
    //Display all movies of a given actor: Tom Cruise, Carrie Fisher, Roger Moore, and two others of your choice.
    cout << endl;
    cout << "Tom Cruise's Movies:" << endl;
    tr.DisplayCertinActors("Tom Cruise");

    cout << endl;
    cout << "Carrie Fisher's Movies:" << endl;
    tr.DisplayCertinActors("Carrie Fisher");

    cout << endl;
    cout << "Roger Moore's Movies:" << endl;
    tr.DisplayCertinActors("Roger Moore");

    cout << endl;
    cout << "Clint Eastwood's Movies:" << endl;
    tr.DisplayCertinActors("Clint Eastwood");

    cout << endl;
    cout << "Matt Damon's Movies:" << endl;
    tr.DisplayCertinActors("Matt Damon");
    //Display all movies released in 1970 and one other year of your choice.
    //tr.printTree();
    tr.deleteTree();
    
    
    return 0;
}