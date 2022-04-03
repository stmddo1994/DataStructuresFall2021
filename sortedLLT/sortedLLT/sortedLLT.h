#pragma once
#ifndef _SORTEDLL_H
#define _SORTEDLL_H

#include <iostream>

using namespace std;

template <class ItemType>
class node
{
public:
	ItemType data;
	node<ItemType>* next;

};

template <class ItemType>
class sortedLLT
{
private:
	node<ItemType>* listData; //pointer to first node
	int length;
	node<ItemType>* currentPos;

public:
	sortedLLT(); //no arg constructor
	void makeEmpty(); //function to make list empty
	bool isFull(); //function to check if list is full
	int getLength(); //returns length of list

	bool findItem(ItemType item); //function to find given item
	//returns true if item is found; false if not

	void putItem(ItemType item); //inserts item in front of linked list
	void deleteItem(ItemType item); //finds item then deletes it if found

	void resetList(); //resets list
	ItemType getNextItem(); //returns next item in list
	void printList(); //prints items in list


};

//Can also try putting whole of sortedLLT.cpp beneath header

#include "sortedLLT.cpp"
#endif