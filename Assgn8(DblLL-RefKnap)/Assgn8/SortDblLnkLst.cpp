//File: SortDblLnkLst.cpp
//Project: CSIS 3400 Assignment 8
//Author: Mathew Doty
//Version: 3.9 Oct 29, 2021

#ifndef _SORTDBLLNKLST_CPP
#define _SORTDBLLNKLST_CPP

#include "SortDblLnkLst.h"

template<class Mathew>
SortDblLnkLst<Mathew>::SortDblLnkLst()
{
	listData = NULL;
	length = 0;
	currentPos = NULL;
}

template<class Mathew>
SortDblLnkLst<Mathew>::~SortDblLnkLst()
{
	Node<Mathew>* tempLocation;
	while (listData != NULL)
	{
		tempLocation = listData;
		listData = listData->next;
		delete tempLocation;
	}
	length = 0;
}

template<class Mathew>
SortDblLnkLst<Mathew>::SortDblLnkLst(const SortDblLnkLst& copy)
{
	cout << "Copy Constructor" << endl;
	Node<Mathew>* ptr1;
	Node<Mathew>* ptr2;
	Node<Mathew>* lastnode;

	if (copy.listData == NULL)
		listData = NULL;
	else
	{
		listData = new Node<Mathew>;
		listData->info = copy.listData->info;
		ptr1 = copy.listData->next;
		ptr2 = listData;
		ptr2->prev = NULL;
		length++;

		while (ptr1 != NULL)
		{
			lastnode = ptr2;
			ptr2->next = new Node<Mathew>;
			ptr2 = ptr2->next;
			ptr2->prev = lastnode;
			ptr2->info = ptr1->info;
			ptr1 = ptr1->next;
			length++;
		}
		ptr2->next = NULL;
	}
}

template<class Mathew>
SortDblLnkLst<Mathew>& SortDblLnkLst<Mathew>::operator=(const SortDblLnkLst& rhs)
{
	cout << "Assignment Operator" << endl;
	Node<Mathew>* ptr1;
	Node<Mathew>* ptr2;
	Node<Mathew>* lastnode;

	if (rhs.listData == NULL)
		listData = NULL;
	else
	{
		listData = new Node<Mathew>;
		listData->info = rhs.listData->info;
		ptr1 = rhs.listData->next;
		ptr2 = listData;
		ptr2->prev = NULL;
		length++;
		while (ptr1 != NULL)
		{
			lastnode = ptr2;
			ptr2->next = new Node<Mathew>;
			ptr2 = ptr2->next;
			ptr2->prev = lastnode;
			ptr2->info = ptr1->info;
			ptr1 = ptr1->next;
			length++;
		}
		ptr2->next = NULL;
	}
	return *this;
	// TODO: insert return statement here
}

template<class Mathew>
bool SortDblLnkLst<Mathew>::isFull()
{
	Node<Mathew>* location;
	try
	{
		location = new Node<Mathew>;
		delete location;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

template<class Mathew>
bool SortDblLnkLst<Mathew>::findItem(Mathew item)
{
	bool moreToSearch;
	Node<Mathew>* location;
	location = listData;
	bool found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->info)
		{
			found = true;
			break;
		}
		else if (item > location->info)
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

template<class Mathew>
void SortDblLnkLst<Mathew>::putItem(Mathew item)
{
	Node<Mathew>* location;
	Node<Mathew>* newNode;
	bool moreToSearch;

	newNode = new Node<Mathew>;
	newNode->info = item;

	location = listData;

	if (location == NULL)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		listData = newNode;
	}
	else if (item <= listData->info)
	{
		newNode->next = location;
		newNode->prev = NULL;
		location->prev = newNode;
		listData = newNode;
	}
	else
	{
		moreToSearch = (location->next != NULL);
		while (moreToSearch)
		{
			if (item > location->info)
			{
				location = location->next;
				moreToSearch = (location->next != NULL);
			}
			else if (item <= location->info)
			{
				moreToSearch = false;
				break;
			}
		}

		if (location->next == NULL && item > location->info)
		{
			newNode->next = NULL;
			newNode->prev = location;
			location->next = newNode;
		}
		else
		{
			newNode->prev = location->prev;
			newNode->next = location;
			newNode->prev->next = newNode;
			location->prev = newNode;
		}
	}

	length++;
}

template<class Mathew>
void SortDblLnkLst<Mathew>::deleteItem(Mathew item)
{
	if (!findItem(item))
		return; //only return needed for void function

	Node<Mathew>* location;
	Node<Mathew>* tempLocation = NULL;
	location = listData;
	bool moreToSearch = (location != NULL);

	if (item == location->info)
	{
		tempLocation = location;
		listData = listData->next;
		if (listData != NULL)
			listData->prev = NULL;
	}
	else
	{
		while (moreToSearch)
		{
			if (item == location->info)
			{
				moreToSearch = false;
				if (location->next != NULL)
					location->next->prev = location->prev;
				location->prev->next = location->next;
				tempLocation = location;
			}
			else if (item > location->info)
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
	}
	delete tempLocation;
	length--;
}

template<class Mathew>
void SortDblLnkLst<Mathew>::resetList()
{
	currentPos = NULL;
}

template<class Mathew>
Mathew SortDblLnkLst<Mathew>::getNextItem()
{
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->info;
}

template<class Mathew>
void SortDblLnkLst<Mathew>::printList()
{
	Mathew item;
	resetList();
	if (length == 0)
		return;
	else
	{
		for (int i = 0; i < length; i++)
		{
			item = getNextItem();
			cout << item << " ";
		}
		cout << endl;
	}
}

template<class Mathew>
void SortDblLnkLst<Mathew>::printListReverse()
{
	resetList();
	if (length == 0)
		return;
	if (currentPos == NULL)
		currentPos = listData;
	while (currentPos->next != NULL)
		currentPos = currentPos->next;
	cout << currentPos->info << " ";
	while (currentPos->prev != NULL)
	{
		currentPos = currentPos->prev;
		cout << currentPos->info << " ";
	}
	cout << endl;
}

#endif