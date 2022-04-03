#pragma once

#pragma once
#ifndef _QUEARRT_H_
#define _QUEARRT_H_

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

#include "QueArrT.cpp"
#endif