/*
    Computer Science 2
    Tree Implementation File

    Collin Worth 11-7-23
*/
#include <iostream>
#include <fstream>
#include "Tree.h"
#include "List.h"
using namespace std;



Tree::Tree(){
    //constructor
    rootPtr = NULL;
};

Tree::~Tree(){
    //deconstructor
};

//gathers all data from a section seperated by blank lines 
//  and adds them to a node on the tree
int Tree::GetData(ifstream& fData){
    if (!fData.is_open()) {
    cerr << "Error: File not found!" << endl;
    return 1;
    }
    string curString;
    string storTitle;
    int storYear = 0;
    string storName;
    int strLoc = 0;
    

    getline(fData, curString);

    while(curString.empty()){ //insures we are using a string with data in it
        getline(fData, curString);
    }

    while(curString[strLoc] != '('){
        storTitle += curString[strLoc];
        strLoc ++;
    }

    strLoc ++;

    while (curString[strLoc] != ')'){
        storYear = (storYear * 10) + (curString[strLoc] - '0');
        strLoc++;
    }

    //  NAMES
    //////////////////////////
    
    List newList;
    while(!curString.empty()){
    
        if(fData.eof()){return 1;}

        newList.AddNode(curString);     

        getline(fData, curString);
    }
 
    AddNodeR(storTitle, storYear, newList);
    if(fData.eof()){
        return 1;
    }else{
        return 0;
    }
}

//public function for AddNodeR
void Tree::AddNodeR( string title, int year, List names){
    AddNodeR( rootPtr, title, year, names);
}

// Add Node based on movie title
void Tree::AddNodeR(Node* &t, string title, int year, List Nlist) {
    if (t == nullptr) {
        t = new Node;
        t->title = title;
        t->year = year;
        t->names = Nlist;
        t->leftPtr = nullptr;
        t->rightPtr = nullptr;
    } else if (title <= t->title) {
        AddNodeR(t->leftPtr, title, year, Nlist);
    } else {
        AddNodeR(t->rightPtr, title, year, Nlist);
    }
}

//public function for printTree
void Tree::printTree(){
    printTree(rootPtr);
}

//prints out all data found in every node in tree
void Tree::printTree(Node* t){

    if(t != NULL){
        printFullNode(t);
        printTree(t ->leftPtr);
        printTree(t ->rightPtr);
    }
}

//prints out all of the data from a specific node "t"
void Tree::printFullNode(Node* t){
    cout << endl;
    cout << "Title: " << t->title << endl;
    cout << "Year: " << t->year << endl;
    cout << "Actors: ";
    t->names.PrintList();
    cout << endl;
}

//public function for deleteTree
void Tree::deleteTree() {
    deleteTree(rootPtr); // Call recursive function starting from the root
    rootPtr = nullptr;   // Set the root to null after the tree is deleted
}

//Dealocate all memory from the tree
void Tree::deleteTree(Node* &t) {
    if (t != nullptr) {
        deleteTree(t->leftPtr);  // Delete left subtree
        deleteTree(t->rightPtr); // Delete right subtree
        delete t;                // Delete current node
        t = nullptr;       // Set node to null to avoid dangling pointers
    }
}

// Return true if node is a leaf
bool Tree::IsLeaf( Node* treePtr) {
    return ((treePtr->leftPtr == NULL) && (treePtr->rightPtr == NULL) );
}

//public function for DisplayTitles
void Tree::DisplayTitles(){
    DisplayTitles(rootPtr);
}

//Prints out all titles currently in the tree
void Tree::DisplayTitles(Node* t) {
    if (t != nullptr) {
        if (t->leftPtr != nullptr) {
            DisplayTitles(t->leftPtr);
        }
        cout << t->title << endl;
        if (t->rightPtr != nullptr) {
            DisplayTitles(t->rightPtr);
        }
    }
}

//public function for DisplayCertinActors
void Tree::DisplayCertinActors(string s){
    DisplayCertinActors(rootPtr, s);
}

//prints out all titles that the actor "s" was an actor in
void Tree::DisplayCertinActors(Node* t, string s){

    //while walking through tree
    if(t != NULL){
        //if one of the actors == string
        if(t->names.LookFor(s)){
            //print movie title
            cout << t->title << endl;
        }
        DisplayCertinActors(t->leftPtr, s);
        DisplayCertinActors(t->rightPtr, s);
    } 
}

//public function for DisplayAllActors
void Tree::DisplayAllActors(string s){
    DisplayAllActors(rootPtr, s);
}

//prints out all of the actors for a specific title "s"
void Tree::DisplayAllActors(Node* t, string s){
    if(t != NULL){
        if(t->title == s){
            t->names.PrintList();
        }
        DisplayAllActors(t->leftPtr, s);
        DisplayAllActors(t->rightPtr, s);
    }
}

//public function for DisplayMoviesReleased
void Tree::DisplayMoviesReleased(int i){
    DisplayMoviesReleased(rootPtr, i);
}

//prints out all of the movie titles released in "i" year
void Tree::DisplayMoviesReleased(Node* t, int i){
    if(t != NULL){
        if(t->year == i){
            cout << t->title << endl;
        }
        DisplayMoviesReleased(t->leftPtr, i);
        DisplayMoviesReleased(t->rightPtr, i);
    }
}