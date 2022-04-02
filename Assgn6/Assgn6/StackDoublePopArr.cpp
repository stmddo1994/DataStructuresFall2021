//File: StackDoublePopArr.cpp
//Project: CSIS 3400 Assignment 6
//Author: Mathew Doty
//Version: 1.3 Oct 14, 2021

#ifndef _STACKDOUBLEPOPARR_CPP_
#define _STACKDOUBLEPOPARR_CPP_

#include "StackDoublePopArr.h"

template <class ItemType>
StackDoublePopArr<ItemType>::StackDoublePopArr()
{
	maxStack = 10;
	top = -1;
	items = new ItemType[maxStack];

}

template <class ItemType>
StackDoublePopArr<ItemType>::StackDoublePopArr(int size)
{
	maxStack = size;
	top = -1;
	items = new ItemType[maxStack];
}

template <class ItemType>
bool StackDoublePopArr<ItemType>::isEmpty()
{
	return (top == -1);
}

template <class ItemType>
bool StackDoublePopArr<ItemType>::isFull()
{
	return (top == maxStack - 1);
}

template <class ItemType>
void StackDoublePopArr<ItemType>::push(ItemType item)
{
	if (isFull())
		cout << "Stack is full; No items can be pushed" << endl;
	else
	{
		top++;
		items[top] = item;
	}
}

template <class ItemType>
void StackDoublePopArr<ItemType>::pop()
{
	if (isEmpty())
		cout << "Stack is empty; No items can be popped" << endl;
	else if (top > 0)
	{
		top--;
		top--;
	}
	else
		top--;
}

template <class ItemType>
void StackDoublePopArr<ItemType>::printStack() const
{
	if (top == -1)
		cout << "Stack is empty" << endl;
	else
	{
		for (int i = 0; i <= top; i++)
			cout << items[i] << " ";
		cout << endl;
	}
}

template <class ItemType>
ItemType StackDoublePopArr<ItemType>::topView() const
{
	//Always return top element
	if (top == -1)
		cout << "Stack is empty" << endl;
	else
		return items[top];
}






template<class ItemType>
StackDoublePopLLT<ItemType>::StackDoublePopLLT()
{
	top = -1;
	listData = NULL;
	currentPos = NULL;
}

template<class ItemType>
bool StackDoublePopLLT<ItemType>::isEmpty() const
{
	return (top == -1);
}

template <class ItemType>
bool StackDoublePopLLT<ItemType>::isFull() const
{
	node<ItemType>* location;
		try
		{
			location = new node<ItemType>;
			delete location;
			return false;
		}
		catch (bad_alloc exception)
		{
			return true;
		}
}

template <class ItemType>
void StackDoublePopLLT<ItemType>::push(ItemType item)
{
	if (isFull())
		cout << "Stack is full; No items can be pushed" << endl;
	else
	{
		top++;
		node<ItemType>* location;
		location = new node<ItemType>;
		location->data = item;
		location->next = listData;
		listData = location;
	}
}
template<class ItemType>
void StackDoublePopLLT<ItemType>::pop()
{
	node<ItemType>* location;
	node<ItemType>* tempLocation;
	node<ItemType>* newFLocation;

	if (isEmpty())
		cout << "Stack is empty; No items can be popped" << endl;
	else if (top > 0)
	{
		location = listData;
		tempLocation = location;
		location = location->next;
		listData = location;
		delete tempLocation;
		top--;
		newFLocation = location;
		if (location->next != NULL)
			location = location->next;
		else
			location = NULL;
		listData = location;
		delete newFLocation;
		top--;
	}
	else
	{
		location = listData;
		listData = NULL;
		delete location;
		top--;
	}
}

template<class ItemType>
ItemType StackDoublePopLLT<ItemType>::topView()
{
	node<ItemType>* location;
	location = listData;
	return location->data;
}

template<class ItemType>
void StackDoublePopLLT<ItemType>::resetList()
{
	currentPos = NULL;
}

template<class ItemType>
ItemType StackDoublePopLLT<ItemType>::getNextItem()
{
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->data;
}

template<class ItemType>
void StackDoublePopLLT<ItemType>::printStack()
{
	ItemType item;
	resetList();
	if (isEmpty())
		cout << "Stack is empty" << endl;
	else
	{
		for (int i = -1; i < top; i++)
		{
			item = getNextItem();
			cout << item << " ";
		}
		cout << endl;
	}
}

#endif