/*
Title: driver.cpp
Abstract: This cpp is used to test the LinkedList class
Author: Evan Schwander
Date: 11/25/14
*/

#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
	// Test the class constructor
	LinkedList intList;
	
	cout << "Constructing intList\n";
	/*
	// Test insert()
	intList.insert(100, 0);
	intList.display(cout);
	cout << endl;

	intList.insert(200, 0);
	intList.display(cout);
	cout << endl;

	intList.insert(300, 1);
	intList.display(cout);
	cout << endl;

	intList.insert(400, 1);
	intList.display(cout);
	cout << endl;

	intList.insert(500, 3);
	intList.display(cout);
	cout << endl;

	// Test destructor
	{
		LinkedList anotherList;
		for (int i = 0; i < 10; i++)
		{
			anotherList.insert(100 * i, i);
		}
		cout << "\nThis is another list\n";
		anotherList.display(cout);
	}

	// Test erase
	intList.erase(1);
	intList.erase(1);
	cout << "\n\nTwo items are erased from the first list\n";
	intList.display(cout);
	cout << endl;
	*/

	intList.insert(100, 0);
	intList.insert(200, 0);
	intList.insert(100, 1);
	intList.insert(400, 1);
	intList.insert(100, 3);
	intList.insert(400, 5);
	intList.display(cout);
	cout << endl << endl;

	cout << "Testing count function for 100: "; // Testing count function
	ElementType test = intList.count(100);
	cout << test << endl;

	cout << "Testing getNth on position 5: "; // testing getNth
	test = intList.getNth(5);
	cout << test << endl;

	cout << "Testing getNth on position 0: "; // testing getNth
	test = intList.getNth(0);
	cout << test << endl;

	cout << "Testing pop. The head equals: "; // testing pop
	test = intList.pop();
	cout << test << endl ;

	cout << "intList after pop: \n";

	intList.display(cout);
	cout << endl << endl;

	LinkedList testList;

	cout << "Creating testList:\n";

	testList.insert(100, 0);
	testList.insert(300, 0);
	testList.insert(200, 1);
	testList.insert(999, 1);
	testList.insert(100, 3);
	testList.insert(400, 5);
	testList.display(cout);
	cout << endl << endl;

	cout << "Appending testList onto intList: \n"; // testing append
	testList.append(intList);
	testList.display(cout);
	cout << endl;

	cout << "Removing duplicates:\n"; // testing duplicates
	testList.duplicates();
	testList.display(cout);
	cout << endl;
	
	cout << "Printing intList to show it was not afected by duplicate deletion: \n";
	intList.display(cout);
	cout << endl << endl;


}