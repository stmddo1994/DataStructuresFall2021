//File: queueList.cpp
//Project: CSIS 3400 Assignment 7
//Author: Mathew Doty
//Version: 2.2 Oct 23, 2021
#ifndef _QUEUELIST_CPP_
#define _QUEUELIST_CPP_

#include "queueList.h"

template<class Mathew>
inline qList_mathew<Mathew>::qList_mathew()
{
	front = NULL;
	rear = NULL;
}

template<class Mathew>
qList_mathew<Mathew>::~qList_mathew()
{
	node<Mathew>* tempLocation;
	rear = NULL;
	while (front != NULL)
	{
		tempLocation = front;
		front = front->next;
		delete tempLocation;
	}
}

template<class Mathew>
bool qList_mathew<Mathew>::isEmpty()
{
	return (front == NULL);
}

template<class Mathew>
bool qList_mathew<Mathew>::isFull()
{
	node<Mathew>* location;
	try
	{
		location = new node<Mathew>;
		delete location;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

template<class Mathew>
bool qList_mathew<Mathew>::findItemQue(Mathew item)
{
	bool moreToSearch;
	node<Mathew>* location;
	location = front;
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

template<class Mathew>
void qList_mathew<Mathew>::addQue(Mathew item)
{
	if (isFull())
		cout << "The queue is completely full; no items can be added" << endl;
	else
	{
		node<Mathew>* location;
		location = new node<Mathew>;
		location->data = item;
		location->next = NULL;

		if (front == NULL)
			front = location;
		else
			rear->next = location;

		rear = location;
	}
}

template<class Mathew>
void qList_mathew<Mathew>::removeQue(Mathew& item)
{
	if (isEmpty())
		cout << "Queue is empty; Nothing to delete" << endl;
	else
	{
		item = front->data;
		node<Mathew>* temploc;
		temploc = front;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		delete temploc;
	}
}

template<class Mathew>
void qList_mathew<Mathew>::printQue()
{
	if (isEmpty())
		cout << "Queue is empty; nothing to display" << endl;
	else
	{
		node<Mathew>* currentPos;
		currentPos = front;
		while (currentPos != rear)
		{
			cout << currentPos->data << " ";
			currentPos = currentPos->next;
		}
		cout << currentPos->data << endl;
	}
}

#endif