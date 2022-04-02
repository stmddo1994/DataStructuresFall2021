//File: Assgn5Main.cpp
//Project: CSIS 3400 Assignment 5
//Author: Mathew Doty
//Version: 1.3 Oct 2, 2021

#include "BufferArrayTempl.h"
#include "sortedRevLLStr.h"

//test main
int main()
{
	//Testing BufferArrayTemp class
	BufferArrayTempl<int> arr = BufferArrayTempl<int>();
	arr.insert(2);
	arr.insert(4);
	arr.insert(3);
	arr.insert(1);
	arr.display();
	arr.insert(6);
	arr.display();
	cout << arr.find(1) << endl;
	arr.fastRemove(3);
	arr.display();
	arr.insert(3);
	arr.stableRemove(4);
	arr.display();

	//String Buffer
	BufferArrayTempl<string> strArr = BufferArrayTempl<string>(6);
	strArr.insert("May");
	strArr.insert("4");
	strArr.insert("Gears");
	strArr.insert("Samuel King");

	//Should display true
	cout << strArr.find("Gears") << endl;
	//Should display false
	cout << strArr.find("Glory") << endl;
	strArr.display();
	//Should remove "4" and replace with "Samuel King"
	strArr.fastRemove("4");
	strArr.display();

	strArr.insert("People");
	strArr.insert("Eggman");
	strArr.insert("Walrus");
	strArr.insert("Football");
	strArr.display();

	//Should remove "Gears" and move others left
	strArr.stableRemove("Gears");
	strArr.display();

	//Testing sortedRevLLStr class and functions
	sortedRevLLStr uslStr = sortedRevLLStr();
	uslStr.printList();
	uslStr.putItem("Honda");
	uslStr.putItem("Toyota");
	uslStr.putItem("Lexus");
	uslStr.putItem("Ford");
	uslStr.printList();

	uslStr.displayListBackwards();
	cout << "Enter a char to find the word in the list" << endl;
	char endChar;
	cin >> endChar;
	cout << uslStr.findWordEndIn(endChar) << endl;
	uslStr.deleteItem("Ford");
	uslStr.printList();

	uslStr.putItem("Chevy");
	uslStr.putItem("Volkswagon");
	cout << "Enter a char to find the word in the list" << endl;
	cin >> endChar;
	cout << uslStr.findWordEndIn(endChar) << endl;
	uslStr.displayListBackwards();
	
	return 0;
}