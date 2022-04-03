#ifndef _UNSORTEDLL_CPP
#define _UNSORTEDLL_CPP

#include "unsortedLLT.h"
//Possible workaround

template <class ItemType>
unsortedLLT<ItemType>::unsortedLLT()
{
	length = 0;
	listData = NULL;
	currentPos = NULL;
}

template <class ItemType>
void unsortedLLT<ItemType>::makeEmpty()
{
	node<ItemType>* tempLocation;
	while (listData != NULL)
	{
		tempLocation = listData;
		listData = listData->next;
		delete tempLocation;
	}
	length = 0;
}

template <class ItemType>
bool unsortedLLT<ItemType>::isFull()
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
int unsortedLLT<ItemType>::getLength()
{
	return length;
}

template <class ItemType>
bool unsortedLLT<ItemType>::findItem(ItemType item)
{
	bool moreToSearch;
	node<ItemType>* location;
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
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}
	return found;
}

template <class ItemType>
void unsortedLLT<ItemType>::putItem(ItemType item)
{
	node<ItemType>* location;
	location = new node<ItemType>;
	location->data = item;
	location->next = listData;
	listData = location;

	length++;
}

template <class ItemType>
void unsortedLLT<ItemType>::deleteItem(ItemType item)
{
	if (!findItem(item))
		return; //only return needed for void function

	node<ItemType>* location;
	node<ItemType>* tempLocation;
	location = listData;
	if (item == location->data)
	{
		tempLocation = location;
		listData = listData->next;
	}
	else
	{
		while (item != location->next->data)
			location = location->next;
		tempLocation = location->next;
		location->next = (location->next)->next;
	}
	delete tempLocation;
	length--;
}

template <class ItemType>
void unsortedLLT<ItemType>::resetList()
{
	currentPos = NULL;
}

template <class ItemType>
ItemType unsortedLLT<ItemType>::getNextItem()
{
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->data;
}

template <class ItemType>
void unsortedLLT<ItemType>::printList()
{
	ItemType item;
	resetList();
	for (int i = 0; i < length; i++)
	{
		item = getNextItem();
		cout << item << " ";
	}
	cout << endl;
}

#endif