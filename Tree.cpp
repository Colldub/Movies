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


void Tree::GetData(ifstream& fData){
    string curString;
    string storTitle;
    int storYear;
    string storName;
    

    getline(fData, curString);
    int length = curString.length();
    //cout << "length of curString: " << length << endl;

    for(int i = 0; i < length; i ++){                                   // get title
        //cout << "current string char: " << curString[i] << endl;        //
        if(curString[i] == '\('){   ///if year is next                  //
            i = length + 10;        ///exit loop                        //
        }else{                                                          // place in storTitle
            storTitle += curString[i]; //add name                       //
        }
    }
    //cout << "exits first loop" << endl;

    size_t i = 0;

    while (i < curString.length() && !isdigit(curString[i])) {
        i++;
    }
    while (i < curString.length() && isdigit(curString[i])) {
        storYear = storYear * 10 + (curString[i] - '0');
        i++;
    }

    //  NAMES
    //////////////////////////
    getline(fData, curString);                                          // get names
    
    List newList;

    while(!curString.empty()){
                                    //cout << "adding :" << curString << endl;
        newList.AddNode(curString);

        getline(fData, curString);
    }
                                    //cout << "this should be empty: " << curString << endl;
    //newList.PrintList();
                                    //cout << "printed" << endl;
    AddNodeR(storTitle, storYear, newList);

                                    //cout << "added" << endl;
}

void Tree::AddNodeR( string title, int year, List names){

    AddNodeR( rootPtr, title, year, names);
}

// Add Node based on movie title
void Tree::AddNodeR( Node* &t, string title, int year, List Nlist){

    if( t == NULL ){

        Node* newPtr = new Node;

    // Add new data in the new node’s data field
        
        newPtr->title = title;
        newPtr->names = Nlist;
        newPtr->year = year;
        newPtr->leftPtr = NULL;
        newPtr->rightPtr = NULL;
        t = newPtr;
    }
    else if( title <= t->title ){
        AddNodeR( t->leftPtr, title, year, Nlist);
    }else{
        AddNodeR( t->rightPtr, title, year, Nlist);
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
bool Tree::IsLeaf( Node* treePtr)
{
    return ((treePtr->leftPtr == NULL) && (treePtr->rightPtr == NULL) );
}