/*
	Palandrome Assignment	CS 121
	Class File
	
	Collin Worth	9-25-2023
*/

#include "List.h"
#include <iostream>

using namespace std;

List::List() : head(nullptr) {}

List::~List() {
    // Deconstructor
}

void List::AddNode(string str) {

    Node* ptr = new Node;
    ptr -> data = str;

    if(head == NULL){
        ptr -> next = NULL;
    }else{
        ptr -> next = head;
    }
    head = ptr;
}

// Print list in order to test code 
void List::PrintList() {
    Node* current = head;
                                        //cout << "start print" << endl;
                                        
    while (current != nullptr) {
        //cout << "curr data: " << current->data << endl;
        cout << current->data;
        if (current->next != nullptr) {
            cout << ", ";
        }
        current = current->next;
    }
    cout << endl;
}

// Implement the Delete function to clean up the list
void List::Delete() {
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

bool List::LookFor(string s){
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == s){
            return true;
        }
        temp = temp->next;
    }
    return false;
}