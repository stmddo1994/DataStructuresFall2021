#include "BSTree_FinalExam.h"
int main()
{
	BSTree<char>bst1;
	bst1.addItemIter('D');
	bst1.addItemIter('B');
	bst1.addItemIter('A');
	bst1.addItemIter('C');
	bst1.addItemIter('F');
	bst1.addItemIter('E');
	bst1.addItemIter('G');
	bst1.printTree();
	bst1.computeOneRightChildNode();
	bst1.isAVLTree();
	bst1.deleteItemIter('G');
	bst1.printTree();
	bst1.isAVLTree();
	bst1.deleteItemIter('D');
	bst1.printTree();
	bst1.isAVLTree();
	return 0;
}