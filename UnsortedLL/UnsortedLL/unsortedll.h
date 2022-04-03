#include <iostream>

using namespace std;

class node
{
public:
	int data;
	node* next;

};

class unsortedLL
{
private:
	node* listData; //pointer to first node
	int length;
	node* currentPos;

public:
	unsortedLL(); //no arg constructor
	unsortedLL(const unsortedLL& another); //deep copy
	void makeEmpty(); //function to make list empty
	bool isFull(); //function to check if list is full
	int getLength(); //returns length of list

	bool findItem(int item); //function to find given item
	//returns true if item is found; false if not

	void putItem(int item); //inserts item in front of linked list
	void deleteItem(int item); //finds item then deletes it if found

	void resetList(); //resets list
	int getNextItem(); //returns next item in list
	void printList(); //prints items in list

	unsortedLL& operator = (const unsortedLL& rhs); //Assignment Operator
};