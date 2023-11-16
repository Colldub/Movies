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
    rootPtr = NULL;
};

Tree::~Tree(){

};


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

    while(curString.empty()){ //insures that we are using a string with data in it
        getline(fData, curString);
    }

    while(curString[strLoc] != '('){
        storTitle += curString[strLoc];
        strLoc ++;
    }

    strLoc ++;

    while (curString[strLoc] != ')'){
        storYear = (storYear * 10) + (curString[strLoc] - '0');  // Convert char to int
        strLoc++;
    }

    //  NAMES
    //////////////////////////
    
    List newList;
    while(!curString.empty()){
                                    //cout << "adding :" << curString << endl;
        if(fData.eof()){return 1;}

        newList.AddNode(curString);     

        getline(fData, curString);
    }
                                    //cout << "this should be empty: " << curString << endl;
    //newList.PrintList();
                                    //cout << "printed" << endl;
    AddNodeR(storTitle, storYear, newList);
    if(fData.eof()){
        return 1;
    }else{
        return 0;
    }
                                    //cout << "added" << endl;
}

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

void Tree::printTree(){
    printTree(rootPtr);
}

void Tree::printTree(Node* t){

    if(t != NULL){
        printFullNode(t);
        printTree(t ->leftPtr);
        printTree(t ->rightPtr);
    }
}

void Tree::printFullNode(Node* t){
    cout << endl;
    cout << "Title: " << t->title << endl;
    cout << "Year: " << t->year << endl;
    cout << "Actors: ";
    t->names.PrintList();
    cout << endl;
}

void Tree::deleteTree(Node* &t) {
    if (t != nullptr) {
        deleteTree(t->leftPtr);  // Delete left subtree
        deleteTree(t->rightPtr); // Delete right subtree
        delete t;                // Delete current node
        t = nullptr;             // Set node to null to avoid dangling pointers
    }
}

void Tree::deleteTree() {
    deleteTree(rootPtr); // Call the recursive function starting from the root
    rootPtr = nullptr;   // Set the root to null after the tree is deleted
}

// Return true if node is a leaf
bool Tree::IsLeaf( Node* treePtr) {
    return ((treePtr->leftPtr == NULL) && (treePtr->rightPtr == NULL) );
}

//public method
void Tree::DisplayTitles(){
    DisplayTitles(rootPtr);
}

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