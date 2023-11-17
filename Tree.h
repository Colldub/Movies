/*
    Computer Science 2
    Tree Header File

    Collin Worth 11-7-23
*/

#ifndef Tree_H
#define Tree_H
#include <string>
#include "List.h"
using namespace std;

class Tree {
    
    public:

        List l;

        struct Node {
            string title;
            List names;
            int year;
            Node* leftPtr;
            Node* rightPtr;
        };

        Tree();
        ~Tree();

        bool IsLeaf(Node*);
        void AddNodeR(string, int, List);
        void removeNode();
        void printTree();
        void deleteTree();
        void printFullNode(Node*);
        int GetData(ifstream&);
        void DisplayTitles();
        void DisplayCertinActors(string);
        void DisplayAllActors(string);
        
    

    private:

        Node* rootPtr;

        void AddNodeR(Node* &, string, int, List);
        void deleteTree(Node* &);
        void printTree(Node*);
        void DisplayTitles(Node*);
        void DisplayCertinActors(Node*, string);
        void DisplayAllActors(Node*, string);

};



#endif