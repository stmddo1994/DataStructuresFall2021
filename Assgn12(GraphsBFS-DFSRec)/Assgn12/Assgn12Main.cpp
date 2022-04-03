//File: Assgn12Main.cpp
//Project: CSIS 3400 Assignment 12
//Author: Mathew Doty
//Version: 2.3 Nov 30, 2021

#include "GraphsBFS.h"

int main()
{
	Graph<char> theGraph;
	theGraph.addVertex('A');
	theGraph.addVertex('B');
	theGraph.addVertex('C');
	theGraph.addVertex('D');
	theGraph.addVertex('E');
	theGraph.addVertex('F');
	theGraph.addVertex('G');
	theGraph.addVertex('H');
	theGraph.addVertex('I');

	theGraph.addEdge('A', 'B', 1);
	theGraph.addEdge('A', 'C', 1);
	theGraph.addEdge('A', 'D', 1);
	theGraph.addEdge('A', 'E', 1);
	theGraph.addEdge('B', 'A', 1);
	theGraph.addEdge('C', 'A', 1);
	theGraph.addEdge('D', 'A', 1);
	theGraph.addEdge('E', 'A', 1);
	theGraph.addEdge('B', 'F', 1);
	theGraph.addEdge('F', 'B', 1);
	theGraph.addEdge('D', 'G', 1);
	theGraph.addEdge('G', 'D', 1);
	theGraph.addEdge('F', 'H', 1);
	theGraph.addEdge('H', 'F', 1);
	theGraph.addEdge('G', 'I', 1);
	theGraph.addEdge('I', 'G', 1);


	theGraph.adjMatrixDisplay();
	theGraph.breadthFirstSearch(0);
	cout << endl;
	theGraph.DFSRec(0);

	return 0;

}