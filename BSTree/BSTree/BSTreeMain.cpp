#include "BSTree.h"

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

	bst1->deleteItemIter('G');

	bst1->printTree();

	bst1->deleteItemIter('D');

	bst1->printTree();

	cout << "Recursive Approach" << endl;

	OrderType io = Post_Order;

	bst1->resetTree(io);
	bool fin = false;
	while (fin == false)
		cout << bst1->getNextItem(io, fin) << " ";
	cout << endl;

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

	bool found;

	bss.getItem(it, found);

	if (found)
		cout << it << " is found in tree";
	else
		cout << it << " is not found in tree;";
	cout << endl;


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


	return 0;
}