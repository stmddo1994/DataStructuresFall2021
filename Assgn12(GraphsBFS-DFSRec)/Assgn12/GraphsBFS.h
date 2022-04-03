//File: GraphBFS.h
//Project: CSIS 3400 Assignment 12
//Author: Mathew Doty
//Version: 3.5 Nov 28, 2021

#include <iostream>
#include "QueArrT.h"

using namespace std;
template<class ItemType >
class Graph
{
public:
	Graph();
	~Graph();
	bool isEmpty() const;
	bool isFull() const;
	void addVertex(ItemType item);
	int indexIs(ItemType* vertices, ItemType vertex);
	void addEdge(ItemType item1, ItemType item2, int wt);
	int getWeight(ItemType item1, ItemType item2);
	void markVertex(ItemType item);
	bool isMarked(ItemType item);
	void clearMarks();
	void breadthFirstSearch(int startVertex);
	int getAdjUnmarkedVertex(ItemType item);
	void adjMatrixDisplay();
	void DFSRec(int startVertex);
private:
	int numVertices;
	int maxVertices = 20;
	ItemType* vertices;
	int edge[20][20];
	bool* marks;
};

#pragma once

template<class ItemType>
Graph<ItemType>::Graph()
{
	numVertices = 0;
	vertices = new ItemType[20];
	marks = new bool[20];
}

template<class ItemType>
Graph<ItemType>::~Graph()
{
	delete[] vertices;
	delete[] marks;
}

template<class ItemType>
inline bool Graph<ItemType>::isEmpty() const
{
	return numVertices == 0;
}

template<class ItemType>
inline bool Graph<ItemType>::isFull() const
{
	return numVertices == maxVertices;
}

template<class ItemType>
void Graph<ItemType>::addVertex(ItemType item)
{
	vertices[numVertices] = item;
	for (int i = 0; i <= numVertices; i++)
	{
		edge[numVertices][i] = 0;
		edge[i][numVertices] = 0;
	}
	numVertices++;
}

template<class ItemType>
int Graph<ItemType>::indexIs(ItemType* vertices, ItemType vertex)
{
	int index = 0;
	while (!(vertex == vertices[index]))
		index++;
	return index;
}

template<class ItemType>
void Graph<ItemType>::addEdge(ItemType fromVertex, ItemType toVertex, int wt)
{
	int row;
	int col;
	row = indexIs(vertices, fromVertex);
	col = indexIs(vertices, toVertex);
	edge[row][col] = wt;
}

template<class ItemType>
int Graph<ItemType>::getWeight(ItemType fromVertex, ItemType toVertex)
{
	int row;
	int col;
	row = indexIs(vertices, fromVertex);
	col = indexIs(vertices, toVertex);
	return edge[row][col];
}

template<class ItemType>
void Graph<ItemType>::markVertex(ItemType item)
{
	for (int index = 0; index < numVertices; index++)
	{
		if (vertices[index] == item)
		{
			marks[index] = true;
			return;
		}
	}
}

template<class ItemType>
bool Graph<ItemType>::isMarked(ItemType item)
{
	for (int index = 0; index < numVertices; index++)
	{
		if (vertices[index] == item)
		{
			return marks[index];
		}
	}
}

template<class ItemType>
void Graph<ItemType>::clearMarks()
{
	for (int index = 0; index < numVertices; index++)
	{
		marks[index] = false;
	}
}

template<class ItemType>
inline void Graph<ItemType>::breadthFirstSearch(int startVertex)
{
	cout << "Breadth First Search" << endl;
	cout << "===================" << endl;
	QueArrT<ItemType> theQueue;
	ItemType vertex = vertices[startVertex];
	ItemType item;
	ItemType front;

	clearMarks();
	markVertex(vertex);
	theQueue.enque(vertex);

	while (!theQueue.isEmpty())
	{
		theQueue.deque(front);
		cout << front << " ";
		int v = getAdjUnmarkedVertex(front);
		while (v != -1)
		{
			item = vertices[v];
			theQueue.enque(item);
			markVertex(item);
			v = getAdjUnmarkedVertex(front);
		}
	}
}

template<class ItemType>
int Graph<ItemType>::getAdjUnmarkedVertex(ItemType item)
{
	int v = -1;
	for (int index = 0; index < numVertices; index++)
	{
		if (vertices[index] == item)
			v = index;
	}
	if (v == -1)
		return v;
	for (int j = 0; j < numVertices; j++)
	{
		if (edge[j][v] == 1)
		{
			if (isMarked(vertices[j]) == false)
				return j;
		}
	}
	return -1;
}

template<class ItemType>
void Graph<ItemType>::adjMatrixDisplay()
{
	int x, y;
	cout << "  "; //Displaying column heads
	for (x = 0; x < numVertices; x++)
		cout << vertices[x] << " ";
	cout << endl;
	for (x = 0; x < numVertices; x++)
		cout << "=";
	cout << endl;
	for (y = 0; y < numVertices; y++)
	{
		cout << vertices[y] << " ";
		for (x = 0; x < numVertices; x++)
			cout << edge[x][y] << " ";
		cout << endl;
	}
}

template<class ItemType>
inline void Graph<ItemType>::DFSRec(int startVertex)
{
	if (startVertex == 0)
	{
		clearMarks();
		cout << "Depth First Search" << endl;
		cout << "===================" << endl;
	}

	ItemType vertex = vertices[startVertex];

	markVertex(vertex);
	cout << vertex << " ";

	int v = getAdjUnmarkedVertex(vertex);
	if (v == -1)
		return;
	else
	{
		while (v != -1)
		{
			DFSRec(v);
			v = getAdjUnmarkedVertex(vertex);
		}
	}
}