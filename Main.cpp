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
    int exit = 0; //used to decied end of file or not

    ifstream fData("Movies.txt"); // open file for use
    while(exit == 0){
        exit = tr.GetData(fData);
    }
    fData.close(); // close file

    
    //Display all movies in the tree (only the titles!).
    tr.DisplayTitles();

    //Display all actors of a given movie in the tree: Bullitt, 
    //  Man of the Year, The April Fools and two others of your choice.
    cout << endl;
    cout << "Actors in Bullitt:" << endl;
    tr.DisplayAllActors("Bullitt ");

    cout << endl;
    cout << "Actors in Man of the Year:" << endl;
    tr.DisplayAllActors("Man of the Year ");

    cout << endl;
    cout << "Actors in The April Fools:" << endl;
    tr.DisplayAllActors("The April Fools ");

    cout << endl;
    cout << "Actors in Good Will Hunting:" << endl;
    tr.DisplayAllActors("Good Will Hunting ");

    cout << endl;
    cout << "Actors in Forrest Gump:" << endl;
    tr.DisplayAllActors("Forrest Gump ");

    //Display all movies of a given actor: Tom Cruise, Carrie Fisher, 
    //  Roger Moore, and two others of your choice.
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
    cout << endl;
    cout << "Movies Released in 1970:" << endl;
    tr.DisplayMoviesReleased(1970);

    cout << endl;
    cout << "Movies Released in 2000:" << endl;
    tr.DisplayMoviesReleased(2000);

    tr.deleteTree();
    
    
    return 0;
}