//File: BufferArrayTempl.cpp
//Project: CSIS 3400 Assignment 5
//Author: Mathew Doty
//Version: 1.1 Sep 30, 2021
#ifndef _BUFFERARRAYTEMPL_CPP
#define _BUFFERARRAYTEMPL_CPP

#include "BufferArrayTempl.h" //Include methods described in header file

//Private location method
template <class ItemType>
int BufferArrayTempl<ItemType>::locationOf(ItemType tar)
{
	for (int i = 0; i < numberOfElements; i++)
	{
		if (tar == typeArray[i])
			return i;
	}
	return -1;
}

template <class ItemType>
bool BufferArrayTempl<ItemType>::find(ItemType t)
{
	if (locationOf(t) == -1)
		return false;
	else
		return true;
}

template <class ItemType>
BufferArrayTempl<ItemType>::BufferArrayTempl()
{
	BUFFER_SIZE = 8;
	typeArray = new ItemType[BUFFER_SIZE];
}

template <class ItemType>
BufferArrayTempl<ItemType>::BufferArrayTempl(int s)
{
	BUFFER_SIZE = s;
	typeArray = new ItemType[BUFFER_SIZE];
}

//Insert number into array
template <class ItemType>
bool BufferArrayTempl<ItemType>::insert(ItemType val)
{
	if (numberOfElements < BUFFER_SIZE)
	{
		typeArray[numberOfElements] = val;
		numberOfElements++;
		return true;
	}
	cout << "Buffer size has reached max" << endl;
	return false;
}

template <class ItemType>
bool BufferArrayTempl<ItemType>::fastRemove(ItemType v)
{
	if (locationOf(v) == -1)
		return false;
	else
	{
		//replace number with last element in array
		typeArray[locationOf(v)] = typeArray[numberOfElements - 1];
		//lower number of elements
		numberOfElements--;
		return true;
	}
}

//show contents of array
template <class ItemType>
void BufferArrayTempl<ItemType>::display()
{
	for (int i = 0; i < numberOfElements; i++)
	{
		//cycle through array and show each element
		cout << typeArray[i];
		//add comma and space only if there is an element after
		if (i + 1 < numberOfElements)
			cout << ", ";
	}
	cout << endl;
}

//Remove element in different manner
template <class ItemType>
bool BufferArrayTempl<ItemType>::stableRemove(ItemType t)
{
	if (locationOf(t) == -1)
		return false;
	else
		for (int i = locationOf(t); i < numberOfElements - 1; i++)
			typeArray[i] = typeArray[i + 1];

	numberOfElements--;
	return true;
}

#endif