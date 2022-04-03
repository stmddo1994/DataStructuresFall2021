//File: StackArrayT.h
//Project: CSIS 3400 Assignment 7
//Author: Mathew Doty
//Version: 3.4 Oct 20, 2021
#pragma once
#ifndef _STACKARRAYT_H_
#define _STACKARRAYT_H_

#include <iostream>

using namespace std;

template<class ItemType>
class StackArrayT
{
private:
	int top;
	int maxStack;
	ItemType* items;

public:
	StackArrayT();
	StackArrayT(int size);
	
	bool isEmpty();
	bool isFull();

	void push(ItemType item);

	void pop(ItemType& item);

	ItemType topView();
	void printStack() const;

	void operator +(ItemType item);
	void operator -();
};

#include "StackArrayT.cpp"
#endif