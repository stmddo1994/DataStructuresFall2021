//File: sortedRevLLStr.h
//Project: CSIS 3400 Assignment 7
//Author: Mathew Doty
//Version: 4.0 Oct 20, 2021
#include <iostream>

using namespace std;

class nodestr
{
public:
	string data;
	nodestr* next;
};

class sortedRevLLStr
{
private:
	nodestr* listData; //pointer to first nodestr
	int length;
	nodestr* currentPos;

public:
	sortedRevLLStr(); //no arg constructor
	void makeEmpty(); //function to make list empty
	bool isFull(); //function to check if list is full
	int getLength(); //returns length of list

	bool findItem(string item); //function to find given item
	//returns true if item is found; false if not

	void putItem(string item); //inserts item in front of linked list
	void deleteItem(string item); //finds item then deletes it if found

	void resetList(); //resets list
	string getNextItem(); //returns next item in list
	void printList(); //prints items in list

	string findWordEndIn(char endAlphabet); //returns string that ends with letter entered
	void displayListBackwards(); //displays list in reverse order
	void displayListBackwardsRec(nodestr* recn); //displays list in reverse order using recursive means
	void displayListBackwardsRecM(); //for use in the main
};

#include "StackArrayT.h"

sortedRevLLStr::sortedRevLLStr()
{
	length = 0;
	listData = NULL;
	currentPos = NULL;
}

void sortedRevLLStr::makeEmpty()
{
	nodestr* tempLocation;
	while (listData != NULL)
	{
		tempLocation = listData;
		listData = listData->next;
		delete tempLocation;
	}
	length = 0;
}

bool sortedRevLLStr::isFull()
{
	nodestr* location;
	try
	{
		location = new nodestr;
		delete location;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

int sortedRevLLStr::getLength()
{
	return length;
}

bool sortedRevLLStr::findItem(string item)
{
	bool moreToSearch;
	nodestr* location;
	location = listData;
	bool found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			break;
		}
		//Sign flipped
		else if (item < location->data)
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else
		{
			moreToSearch = false;
			break;
		}
	}
	return found;
}

void sortedRevLLStr::putItem(string item)
{
	nodestr* location;
	nodestr* prevLoc;
	nodestr* newNode;

	bool moreToSearch;

	location = listData;
	prevLoc = NULL;
	moreToSearch = (location != NULL);

	while (moreToSearch)
	{
		//Signs flipped
		if (item < location->data)
		{
			prevLoc = location;
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else if (item > location->data)
		{
			moreToSearch = false;
			break;
		}
	}

	newNode = new nodestr;
	newNode->data = item;
	if (prevLoc == NULL)
	{
		newNode->next = listData;
		listData = newNode;
	}
	else
	{
		newNode->next = location;
		prevLoc->next = newNode;
	}

	length++;
}

void sortedRevLLStr::deleteItem(string item)
{
	if (!findItem(item))
		return;
	nodestr* location;
	nodestr* prevLocation;
	nodestr* tempLocation = NULL;
	location = listData;
	prevLocation = NULL;
	bool moreToSearch = (location != NULL);

	if (item == location->data)
	{
		tempLocation = location;
		listData = listData->next;
	}
	else
	{
		while (moreToSearch)
		{
			if (item == location->data)
			{
				moreToSearch = false;
				tempLocation = location;
				prevLocation->next = location->next;
			}
			//Sign flipped
			else if (item < location->data)
			{
				prevLocation = location;
				location = location->next;
				moreToSearch = (location != NULL);
			}
			else
			{
				moreToSearch = false;
				break;
			}
		}
	}
	delete tempLocation;
	length--;

}

void sortedRevLLStr::resetList()
{
	currentPos = NULL;
}

string sortedRevLLStr::getNextItem()
{
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->data;
}

void sortedRevLLStr::printList()
{
	string item;
	resetList();
	for (int i = 0; i < length; i++)
	{
		item = getNextItem();
		cout << item << " ";
	}
	cout << endl;
}

string sortedRevLLStr::findWordEndIn(char endA)
{
	//Set default of word to "not found"
	string word = "Not found";
	//test word placeholder
	string test;
	bool moreToSearch;
	nodestr* location;
	location = listData;
	moreToSearch = (location != NULL);

	while (moreToSearch)
	{
		//placeholder becomes word at current location
		test = location->data;
		//if character found at the end of the placeholder string
		if (endA == test.at(test.length() - 1))
		{
			//placeholder becomes found word
			word = test;
			break;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}
	return word;
}

void sortedRevLLStr::displayListBackwards()
{
	string item;
	StackArrayT<string> backl = StackArrayT<string>(length);
	resetList();
	for (int i = 0; i < length; i++)
	{
		item = getNextItem();
		backl.push(item);
	}
	//Added ItemType& to StackArrayT.cpp pop function
	string ipop;
	for (int i = 0; i < length; i++)
	{
		backl.pop(ipop);
		cout << ipop << " ";
	}
	cout << endl;
}

inline void sortedRevLLStr::displayListBackwardsRec(nodestr* recn)
{
	if (recn == NULL)
	{
		return;
	}
	else
	{
		displayListBackwardsRec(recn->next);
		cout << recn->data << " ";
	}
}

inline void sortedRevLLStr::displayListBackwardsRecM()
{
	displayListBackwardsRec(listData);
	cout << endl;
}