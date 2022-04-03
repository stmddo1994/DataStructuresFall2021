//File: BSTree_Final_Main.cpp
//Project: CSIS 3400 Assignment 10
//Author: Mathew Doty
//Version: 2.4 Nov 12, 2021

#include "BSTree_Final.h"

int main()
{
	BSTree<char>* bst1 = new BSTree<char>();

	bst1->addItemIter('D');
	bst1->addItemIter('B');
	bst1->addItemIter('A');
	bst1->addItemIter('C');
	bst1->addItemIter('F');
	bst1->addItemIter('E');
	bst1->addItemIter('G');

	bst1->printTree();

	cout << bst1->calcMinMathew() << endl;
	cout << bst1->calcMaxMathew() << endl;

	bst1->computeOneChildNodesMathewMain();

	bst1->countNodesMathewMain();

	bst1->deleteItemIter('G');

	bst1->printTree();

	bst1->deleteItemIter('D');

	bst1->printTree();

	bst1->computeOneChildNodesMathewMain();

	cout << "Recursive Approach" << endl;

	OrderType io = Post_Order;

	bst1->resetTree(io);
	bool fin = false;
	while (fin == false)
		cout << bst1->getNextItem(io, fin) << " ";
	cout << endl;

	bst1->countNodesMathewMain();

	BSTree<string> bss;

	bss.addItem("Ford");
	bss.addItem("Toyota");
	bss.addItem("Kia");
	bss.addItem("Chevy");
	bss.addItem("Fiat");
	bss.addItem("Volkswagen");

	bss.printTree();

	bss.deleteItem("Kia");
	bss.printTree();

	//bss.deleteItem("Honda");
	//bss.printTree();

	string it;
	cout << "Please enter an item to search" << endl;

	cin >> it;

	bss.findNodeMathewMain(it);

	bss.computeOneChildNodesMathewMain();

	cout << bss.calcMinMathew() << endl;
	cout << bss.calcMaxMathew() << endl;

	//OrderType io = Post_Order;

	bss.resetTree(io);
	fin = false;
	while (fin == false)
		cout << bss.getNextItem(io, fin) << " ";
	cout << endl;

	io = Pre_Order;
	bss.resetTree(io);
	fin = false;
	while (fin == false)
		cout << bss.getNextItem(io, fin) << " ";
	cout << endl;

	bss.deleteAllNodesMathewMain();

	bss.addItemIter("Kia");
	bss.addItemIter("Ford");
	bss.addItemIter("Chevy");
	bss.addItemIter("General Motors");

	bss.printTree();


	return 0;
}