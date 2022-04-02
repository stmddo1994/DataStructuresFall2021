//File: StackDoublePopArr.h
//Project: CSIS 3400 Assignment 6
//Author: Mathew Doty
//Version: 1.0 Oct 14, 2021

#pragma once
#ifndef _STACKDOUBLEPOPARR_H_
#define _STACKDOUBLEPOPARR_H_

#include <iostream>

using namespace std;

template<class ItemType>
class StackDoublePopArr
{
private:
	int top;
	int maxStack;
	ItemType* items;

public:
	StackDoublePopArr();
	StackDoublePopArr(int size);

	bool isEmpty();
	bool isFull();

	void push(ItemType item);

	void pop();

	ItemType topView() const;
	void printStack() const;
};

template <class ItemType>
class node
{
public:
	ItemType data;
	node<ItemType>* next;

};

template<class ItemType>
class StackDoublePopLLT
{
private:
	node<ItemType>* listData;
	int top;
	//Deleted maxStack
	node<ItemType>* currentPos;

public:
	StackDoublePopLLT();
	//Deleted size constructor

	bool isEmpty() const;
	bool isFull() const;

	void push(ItemType item);

	void pop();

	ItemType topView();
	void resetList();
	ItemType getNextItem();
	void printStack();
};


#include "StackDoublePopArr.cpp"
#endif


