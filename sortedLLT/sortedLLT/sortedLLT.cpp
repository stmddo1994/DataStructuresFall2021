#ifndef _SORTEDLL_CPP
#define _SORTEDLL_CPP

#include "sortedLLT.h"
//Possible workaround

template <class ItemType>
sortedLLT<ItemType>::sortedLLT()
{
	length = 0;
	listData = NULL;
	currentPos = NULL;
}

template <class ItemType>
void sortedLLT<ItemType>::makeEmpty()
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
bool sortedLLT<ItemType>::isFull()
{
	node<ItemType>* location;
	try
	{
		location = new node;
		delete location;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

template <class ItemType>
int sortedLLT<ItemType>::getLength()
{
	return length;
}

template <class ItemType>
bool sortedLLT<ItemType>::findItem(ItemType item)
{
	//Change 1
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
		else if (item > location->data)
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

template <class ItemType>
void sortedLLT<ItemType>::putItem(ItemType item)
{
	//Change 3
	node<ItemType>* location;
	node<ItemType>* prevLoc;
	node<ItemType>* newNode;

	bool moreToSearch;

	location = listData;
	prevLoc = NULL;
	moreToSearch = (location != NULL);

	while (moreToSearch)
	{
		if (item > location->data)
		{
			prevLoc = location;
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else if (item < location->data)
		{
			moreToSearch = false;
			break;
		}
	}

	newNode = new node<ItemType>;
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

template <class ItemType>
void sortedLLT<ItemType>::deleteItem(ItemType item)
{
	//Change 2
	if (!findItem(item))
		return; //only return needed for void function
	node<ItemType>* location;
	node<ItemType>* prevLocation;
	node<ItemType>* tempLocation = NULL;
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
			else if (item > location->data)
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

template <class ItemType>
void sortedLLT<ItemType>::resetList()
{
	currentPos = NULL;
}

template <class ItemType>
ItemType sortedLLT<ItemType>::getNextItem()
{
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->data;
}

template <class ItemType>
void sortedLLT<ItemType>::printList()
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