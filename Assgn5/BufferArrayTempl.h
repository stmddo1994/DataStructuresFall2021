//File: BufferArrayTempl.h
//Project: CSIS 3400 Assignment 5
//Author: Mathew Doty
//Version: 1.3 Sept 29, 2021
#pragma once
#ifndef _BUFFERARRAYTEMPL_H
#define _BUFFERARRAYTEMPL_H

#include <iostream>

using namespace std;

//Header to create class for Buffer Array
//Add template
template <class ItemType>
class BufferArrayTempl
{
	//private methods
protected:
	int BUFFER_SIZE;
	ItemType* typeArray;
	int numberOfElements = 0;
	int locationOf(ItemType target);

	//public methods
public:
	BufferArrayTempl(); //NoArg Constructor

	BufferArrayTempl(int size); //Arg Constructor

	bool insert(ItemType value);

	bool fastRemove(ItemType value);

	bool find(ItemType target);

	void display();

	bool stableRemove(ItemType target);

};

#include "BufferArrayTempl.cpp"
#endif