#pragma once
#pragma once
#ifndef _QUEARRAYT_H
#define _QUEARRAYT_H
#include <iostream>
using namespace std;
template<class ItemType>
class QueArrT
{
private:
	int front;
	int rear;
	int maxSize;
	ItemType* items;
public:
	QueArrT();
	QueArrT(int size);
	~QueArrT();
	bool isEmpty();
	bool isFull();
	void enque(ItemType item);
	void deque(ItemType& item);
	void printQue() const;
};
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
	return ((rear + 1) % maxSize == front);
}
template <class ItemType>
void QueArrT<ItemType>::enque(ItemType item)
{
	if (isFull())
		cout << "Queue is full and no item can be added" << endl;
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
		cout << "Q is empty and there is nothing to Deque." << endl;
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
		cout << "Q is empty and there is nothing to print." << endl;
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
