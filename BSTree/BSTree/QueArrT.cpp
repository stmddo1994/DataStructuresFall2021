#ifndef _QUEARRT_CPP_
#define _QUEARRT_CPP_

#include "QueArrT.h"

template <class ItemType>
QueArrT<ItemType>::QueArrT()
{
	maxSize = 10;
	front = maxSize - 1;
	rear = maxSize - 1;
	items = new ItemType[maxSize];

}

template <class ItemType>
QueArrT<ItemType>::QueArrT(int size)
{
	maxSize = size;
	front = maxSize - 1;
	rear = maxSize - 1;
	items = new ItemType[maxSize];
}

template <class ItemType>
QueArrT<ItemType>::~QueArrT()
{
	//cout << "Destructor called" << endl;
	delete[] items;
}

template <class ItemType>
bool QueArrT<ItemType>::isEmpty()
{
	return (rear == front);
}

template <class ItemType>
bool QueArrT<ItemType>::isFull()
{
	return ((rear + 1)%maxSize == front);
}

template <class ItemType>
void QueArrT<ItemType>::enque(ItemType item)
{
	if (isFull())
		cout << "Queue is full; no item can be added" << endl;
	else
	{
		rear = (rear + 1) % maxSize;
		items[rear] = item;
	}
}

template <class ItemType>
void QueArrT<ItemType>::deque(ItemType& item)
{
	if (isEmpty())
		cout << "Queue is empty; nothing to delete" << endl;
	else
	{
		front = (front + 1) % maxSize;
		item = items[front];
	}
}

template <class ItemType>
void QueArrT<ItemType>::printQue() const
{
	if (rear == front)
		cout << "Queue is empty; nothing to display" << endl;
	else
	{
		int temp = front;
		while (temp != rear)
		{
			temp = (temp + 1) % maxSize;
			cout << items[temp] << " ";
		}
		cout << endl;
	}
}

#endif