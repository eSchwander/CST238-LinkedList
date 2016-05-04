/*
 Title: LinkedList.cpp
 Abstract: This cpp contains the member function definitions of the LinkedList class
 Author: Evan Schwander
 Date: 11/25/14
*/


#include <iostream>
using namespace std;

#include "LinkedList.h"

//-- Default constructor
LinkedList::LinkedList()
{
	mySize = 0;
	first = NULL;
}

//-- Definition of the copy constructor
LinkedList::LinkedList(const LinkedList & origList)
{
	mySize = origList.mySize;
	first = NULL;

	if (mySize == 0)
		return;

	Node * origPtr, *lastPtr;
	first = new Node(origList.first->data); // copy first node
	lastPtr = first;
	origPtr = origList.first->next;
	while (origPtr != NULL)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	}
}


//-- Definition of the destructor
LinkedList::~LinkedList()
{
	Node * prev = first;
	Node * ptr;

	while (prev != NULL)
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}
}

// Traverse the LinkedList and process data in each node
void LinkedList::traverse()
{
	Node * ptr = first;
	ElementType sum = 0;

	while (ptr != NULL)
	{
		// Process part of data
		// For example find sum of all data.
		sum += ptr->data;
		ptr = ptr->next;
	}
	return;
}


//-- Definition of insert()
void LinkedList::insert(ElementType dataVal, int index)
{
	if (index < 0 || index > mySize)
	{
		cerr << "Illegal location to insert -- " << index << endl;
		return;
	}

	mySize++;
	Node * newPtr = new Node(dataVal);
	Node * predPtr = first;
	if (index == 0)
	{
		newPtr->next = first;
		first = newPtr;
	}
	else
	{
		for (int i = 1; i < index; i++)
			predPtr = predPtr->next;
		newPtr->next = predPtr->next;
		predPtr->next = newPtr;
	}
}


//-- Definition of erase()
void LinkedList::erase(int index)
{
	if (index < 0 || index >= mySize)
	{
		cerr << "Illegal location to delete -- " << index << endl;
		return;
	}

	mySize--;
	Node * ptr;
	Node * predPtr = first;
	if (index == 0)
	{
		ptr = first;
		first = ptr->next;
		delete ptr;
	}
	else
	{
		for (int i = 1; i < index; i++)
			predPtr = predPtr->next;
		ptr = predPtr->next;
		predPtr->next = ptr->next;
		delete ptr;
	}
}



//-- Definition of display()
void LinkedList::display(ostream & out) const
{
	Node * ptr = first;
	while (ptr != 0)
	{
		out << ptr->data << " ";
		ptr = ptr->next;
	}
}


int LinkedList::count(int num){
	Node * ptr = first;
	int count = 0;

	while (ptr != NULL){ // List is traversed and count is incremented each time the chosen num is found
		if (ptr->data == num){
			count++;
		}
		ptr = ptr->next;
	}

	return count;
}

ElementType LinkedList::getNth(int index){
	Node * ptr = first;
	ElementType num;

	if (index >= mySize || index < 0){ // checks if index is valid
		cout << "Index is outside of the list.\n";
		return 0;
	}

	else if (index == 0){ // checks if index is 0
		num = ptr->data;
		return num;
	}

	else{ // if neither of the previous conditions are true, the list is traversed
		for (int i = 1; i <= index; i++){
			ptr = ptr->next;
		}
		num = ptr->data;
		return num;
	}
	

}

ElementType LinkedList::pop(){
	Node * ptr = first;
	ElementType head;
	int count = 0;

	if (first == NULL){ // If the list is empty, the function lets you know
		cout << "LIST IS EMPTY\n";
		return 0;
	}
	else{
		while (1){ // cycles through list until it finds the head. 
			if (ptr->next == NULL){ 
				head = ptr->data;
				erase(count); // erase is invoked
				return head; // head is erased and returned. mySize is also decreased by 1
			}
			ptr = ptr->next;
			count++;
		}
	}
}

void LinkedList::append(const LinkedList & b){ // List b is appended to this list. 
	Node * ptr = first;
	int count = 1;

	if (b.first == first){ // prevents attempting to add list to itself. Adding a list to itself would create an infinite loop.
		cout << "Cannot append the same list to itself.\n";
		return;
	}
		
	
	if (b.mySize == 0) // If the second list is empty nothing happens.
		cout << "The second list is empty. There is nothing to append.\n";

	else{
		while (ptr->next != NULL){ // First list is traveresed to the end
			ptr = ptr->next;
			count++;
		}
		ptr = b.first;
		while (ptr != NULL){ // All of the Nodes from list b are insterted on the end of list a
			insert(ptr->data, count); // insert is invoked for this
			count++;
			ptr = ptr->next;
		}
	}
}

void LinkedList::duplicates(){
	Node * ptr, * dupePtr = first; // dupePtr points to a Node while ptr traverses the list to search for duplicates
	int count = 0, dupeCount = 0; // count is used to keep track of index

	while (dupePtr != NULL){ // loops to the end of the list
		count = dupeCount+1;
		ptr = dupePtr->next;
		while (ptr != NULL){// In this loop, ptr traverses the list and if it finds a node with data equal to dupePtr the node is deleted
			
			if (ptr->data == dupePtr->data){ 
				ptr = ptr->next;
				erase(count); // erase function is invoked to delete nodes
			}
			else {
				ptr = ptr->next;
				count++;
			}
			
		}
		dupePtr = dupePtr->next;
		dupeCount++;
	}

}