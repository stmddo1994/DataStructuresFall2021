//File: queueList.h
//Project: CSIS 3400 Assignment 7
//Author: Mathew Doty
//Version: 2.1 Oct 23, 2021
#pragma once
#ifndef _QUEUELIST_H_
#define _QUEUELIST_H_

#include <iostream>

using namespace std;

template<class Mathew>
struct node
{
	Mathew data;
	node<Mathew>* next;
};

template<class Mathew>
class qList_mathew
{
private:
	node<Mathew>* front;
	node< Mathew >* rear;
public:
	qList_mathew();
	~qList_mathew();
	bool isEmpty();
	bool isFull();

	bool findItemQue(Mathew item);
	void addQue(Mathew item);
	void removeQue(Mathew& item);

	void printQue();
};

#include "queueList.cpp"
#endif
