#include "unsortedLLMT.h"

unsortedLLMT::unsortedLLMT()
{
	listData = NULL;
	currentPos = NULL;
}

void unsortedLLMT::makeEmpty()
{
	node* tempLocation;
	while (listData != NULL)
	{
		tempLocation = listData;
		listData = listData->next;
		delete tempLocation;
	}
	

}

bool unsortedLLMT::isFull()
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


bool unsortedLLMT::findItem(int item)
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

void unsortedLLMT::putItem(int item)
{
	node* location;
	location = new node;
	location->data = item;
	location->next = listData;
	listData = location;

}

void unsortedLLMT::deleteItem(int item)
{
	if (!findItem(item))
		return;
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
		while ((item != location->next->data) && location->next!= NULL )
			location = location->next;
		tempLocation = location->next;
		location->next = (location->next)->next;
	}
	delete tempLocation;
	
}

void unsortedLLMT::resetList()
{
	currentPos = NULL;
}

int unsortedLLMT::getNextItem()
{
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	return currentPos->data;
}

void unsortedLLMT::printNodes()
{
	int item;
	int itemcount = 0;
	resetList();
	for (int i = 0; i < length; i++)
	{
		item = getNextitem();
		itemcount++;
	}
	cout << itemcount << endl;

	if (itemcount != 0)
	{
		for (int i = 0; i < length; i++)
		{
			item = getNextItem();
			cout << item << " ";
		}
		cout << endl;
	}
}

bool unsortedLLMT::deleteNminus1thNode()
{
	if (length < 1)
		return false;

	node<ItemType>* location;
	node<ItemType>* tempLocation;
	location = listData;
	if (location->next != null)
	{
		tempLocation = location;
		listData = listData->next;
	}
	else
	{
		delete tempLocation;
		length--;
	}
}