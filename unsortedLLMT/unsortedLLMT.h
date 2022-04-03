#include <iostream>

using namespace std;

class node
{
public:
	int data;
	node* next;
};

class unsortedLLMT
{
private:
	node* listData;
	node* currentPos;

public:
	unsortedLLMT();      //No argConstructor
	void makeEmpty();  // Function to make the list empty
	bool isFull();     // Function to check whether the list is full
	

	//Returns true if item is found or returns false if item is not found
	bool findItem(int item); //Function to find the given item. 
	void putItem(int item); //Inserts an item in the front of the linked list
	void deleteItem(int item); //Finds an item, if found deletes it

	void resetList(); //Resets the list
	int getNextItem(); //Returns the next Item in the list
	
	void printNodes();
	bool deleteNminus1thNode();
		
};
