/************************************
* Programmer: Sophia Omar
* Assignment: Serendipity Upgrade
* Due Date: December 16 2025
* Purpose: Demonstrating how to upgrade
*       Serendipity with linked lists
*************************************/
#include <iostream>
#include "bookInfo.h"
using namespace std;

/****************** Operator overload to add into bookInfo.h & .cpp *********************//
//bool operator<(const bookInfo& rhs) const;  ---> put this into the h bc commented out so theres not a compiler prob

//this one 
bool operator<(const bookInfo& rhs) const{
	if(getISBN() == rhs.getISBN())
		return getISBN() < rhs.getISBN(); 
	else
		return getTitle() < rhs.getTitle();
}





/******************* Linked List related stuff***********************/

//Initialize the struct for bookType
struct bookNode {
		int data; 
		bookNode* next; 
};


//if i want to be able to insert the new sorted nodes then you would have to modify the actual bookInfo.h file
//using the template ordered logic given in class

void insertOrdered(bookNode*& head, bookNode*& tail, bookInfo* bookPtr)
{
    bookNode* newNode = new bookNode;
    newNode->data = bookPtr;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    bookNode* current = head;
    bookNode* trail   = NULL;

    // Use overloaded operator< on bookType
    while (current != NULL && *(current->data) < *bookPtr) {
        trail = current;
        current = current->next;
    }

    if (current == head) {              // insert at front
        newNode->next = head;
        head = newNode;
    }
    else if (current == NULL) {         // insert at end
        tail->next = newNode;
        tail = newNode;
    }
    else {                              // insert in the middle
        trail->next = newNode;
        newNode->next = current;
    }
}
