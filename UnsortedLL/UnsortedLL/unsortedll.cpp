#include "unsortedll.h"
unsortedLL::unsortedLL()
{
	length = 0;
	listData = NULL;
	currentPos = NULL;
}

unsortedLL::unsortedLL(const unsortedLL& another)
{
	cout << "Copy Constructor" << endl;
	node* ptr1;
	node* ptr2;

	if (another.listData == NULL)
		listData = NULL;
	else
	{
		listData = new node;
		listData->data = another.listData->data;
		ptr1 = another.listData->next;
		ptr2 = listData;
		length++;

		while (ptr1 != NULL)
		{
			ptr2->next = new node;
			ptr2 = ptr2->next;
			ptr2->data = ptr1->data;
			ptr1 = ptr1->next;
			length++;
		}
		ptr2->next = NULL;
	}

}

void unsortedLL::makeEmpty()
{
	node* tempLocation;
	while (listData != NULL)
	{
		tempLocation = listData;
		listData = listData->next;
		delete tempLocation;
	}
	length = 0;
}

bool unsortedLL::isFull()
{
	node* location;
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

int unsortedLL::getLength()
{
	return length;
}

bool unsortedLL::findItem(int item)
{
	bool moreToSearch;
	node* location;
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

void unsortedLL::putItem(int item)
{
	node* location;
	location = new node;
	location->data = item;
	location->next = listData;
	listData = location;

	length++;
}

void unsortedLL::deleteItem(int item)
{
	if (!findItem(item))
		return; //only return needed for void function

	node* location;
	node* tempLocation;
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

void unsortedLL::resetList()
{
	currentPos = NULL;
}

int unsortedLL::getNextItem()
{
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->data;
}

void unsortedLL::printList()
{
	int item;
	resetList();
	for (int i = 0; i < length; i++)
	{
		item = getNextItem();
		cout << item << " ";
	}
	cout << endl;
}

unsortedLL& unsortedLL::operator=(const unsortedLL& rhs)
{
	cout << "Assignment Operator" << endl;
	node* ptr1;
	node* ptr2;

	if (rhs.listData == NULL)
		listData = NULL;
	else
	{
		listData = new node;
		listData->data = rhs.listData->data;
		ptr1 = rhs.listData->next;
		ptr2 = listData;
		length++;

		while (ptr1 != NULL)
		{
			ptr2->next = new node;
			ptr2 = ptr2->next;
			ptr2->data = ptr1->data;
			ptr1 = ptr1->next;
			length++;
		}
		ptr2->next = NULL;
	}
	return *this;
}
