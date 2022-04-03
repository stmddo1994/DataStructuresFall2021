//File: SortDblLnkLst.h
//Project: CSIS 3400 Assignment 8
//Author: Mathew Doty
//Version: 4.3 Oct 27, 2021

#pragma once
#ifndef _SORTDBLLNKLST_H
#define _SORTDBLLNKLST_H

#include <iostream>

using namespace std;

template<class Mathew>
class Node
{
public:
    Mathew info;
    Node<Mathew>* next;
    Node<Mathew>* prev;
};

template<class Mathew>
class SortDblLnkLst
{
private:
	Node<Mathew>* listData; //pointer to first node
	int length;
	Node<Mathew>* currentPos;

public:
	SortDblLnkLst(); //no arg constructor
	~SortDblLnkLst(); //destructor
	SortDblLnkLst(const SortDblLnkLst& another); //deep copy
	SortDblLnkLst& operator = (const SortDblLnkLst& rhs); //Assignment Operator
	bool isFull(); //function to check if list is full

	bool findItem(Mathew item); //function to find given item
	//returns true if item is found; false if not

	void putItem(Mathew item); //inserts item in front of linked list
	void deleteItem(Mathew item); //finds item then deletes it if found

	void resetList(); //resets list
	Mathew getNextItem(); //returns next item in list
	void printList(); //prints items in list
	void printListReverse(); //prints items on list in reverse
};

#include "SortDblLnkLst.cpp"
#endif