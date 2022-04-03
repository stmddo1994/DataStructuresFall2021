//File: StackArrayT.cpp
//Project: CSIS 3400 Assignment 7
//Author: Mathew Doty
//Version: 3.6 Oct 20, 2021
#ifndef _STACKARRAYT_CPP_
#define _STACKARRAYT_CPP_

#include "StackArrayT.h"

template <class ItemType>
StackArrayT<ItemType>::StackArrayT()
{
	maxStack = 10;
	top = -1;
	items = new ItemType[maxStack];

}

template <class ItemType>
StackArrayT<ItemType>::StackArrayT(int size)
{
	maxStack = size;
	top = -1;
	items = new ItemType[maxStack];
}

template <class ItemType>
bool StackArrayT<ItemType>::isEmpty()
{
	return (top == -1);
}

template <class ItemType>
bool StackArrayT<ItemType>::isFull()
{
	return (top == maxStack - 1);
}

template <class ItemType>
void StackArrayT<ItemType>::push(ItemType item)
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
void StackArrayT<ItemType>::pop(ItemType& item)
{
	if (isEmpty())
		cout << "Stack is empty; No items can be popped" << endl;
	else
	{
		item = items[top];
		top--;
	}
}

template <class ItemType>
void StackArrayT<ItemType>::printStack() const
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

template<class ItemType>
void StackArrayT<ItemType>::operator+(ItemType item)
{
	if (isFull())
		cout << "Stack is full; No items can be pushed" << endl;
	else
	{
		top++;
		items[top] = item;
	}
}

template<class ItemType>
void StackArrayT<ItemType>::operator-()
{
	if (isEmpty())
		cout << "Stack is empty; No items can be popped" << endl;
	else
	{
		top--;
	}
}

template <class ItemType>
ItemType StackArrayT<ItemType>::topView()
{
	//Always return top element
	if (top == -1)
		cout << "Stack is empty" << endl;
	else
		return items[top];
}

#endif