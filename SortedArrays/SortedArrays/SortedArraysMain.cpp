//File: SortedArrays.h
//Project: CSIS 3400 Assignment 4
//Author: Mathew Doty
//Version: 3.1 Sep 24, 2021

#include "SortedArrays.h"

int main()
{
	SortedArrayBufferNoDups sortnd = SortedArrayBufferNoDups(5);

	sortnd.insert(5);
	sortnd.insert(3);
	sortnd.insert(6);
	//Should not include another 5; should display message
	cout << sortnd.insert(5) << endl;
	sortnd.insert(4);
	sortnd.insert(8);
	//Should not include 9; Buffer limit reached
	sortnd.insert(9);
	//Should return true
	cout << sortnd.find(5) << endl;
	//Should return false
	cout << sortnd.find(9) << endl;
	sortnd.display();
	//Should remove 6
	sortnd.stableRemove(6);
	sortnd.display();
	sortnd.insert(7);
	sortnd.display();

	cout << "--------------------------------" << endl;

	SortedArrayBufferWithDups sortwd = SortedArrayBufferWithDups(6);

	sortwd.insert(5);
	sortwd.insert(3);
	sortwd.insert(6);
	//Another 5 should be included
	cout << sortwd.insert(5) << endl;
	sortwd.insert(4);
	sortwd.insert(8);
	//Should not insert 2; Buffer limit reached
	sortwd.insert(2);
	cout << sortwd.find(5) << endl;
	cout << sortwd.find(9) << endl;
	sortwd.display();
	//Should return 2 for both
	cout << sortwd.findAll(5) << endl;
	cout << sortwd.stableRemoveAll(5) << endl;
	//Both 5s should be removed
	sortwd.display();
	sortwd.stableRemove(6);
	sortwd.stableRemove(3);
	sortwd.insert(7);
	sortwd.insert(7);
	sortwd.insert(13);
	sortwd.insert(7);
	//Should have 3 7s
	sortwd.display();
	//Both should return 3
	cout << sortwd.findAll(7) << endl;
	cout << sortwd.stableRemoveAll(7) << endl;
	//All 7s should be removed
	sortwd.display();

	return 0;
}
