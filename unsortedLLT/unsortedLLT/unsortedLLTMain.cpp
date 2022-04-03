#include "unsortedLLT.h"

int main()
{
	unsortedLLT<int> usl = unsortedLLT<int>();

	usl.printList();
	usl.putItem(3);
	usl.putItem(1);
	usl.putItem(9);
	usl.putItem(5);
	usl.printList();

	cout << "Enter a value to find" << endl;
	int findVal;
	cin >> findVal;

	if (usl.findItem(findVal) == true)
		cout << findVal << " is found in the list" << endl;
	else
		cout << findVal << " is not found in the list" << endl;

	usl.deleteItem(99);
	usl.printList();

	unsortedLLT<string> uslStr = unsortedLLT<string>();
	uslStr.printList();
	uslStr.putItem("Honda");
	uslStr.putItem("Lexus");
	uslStr.putItem("Toyota");
	uslStr.putItem("Ford");
	uslStr.printList();

	cout << "Enter a value to find" << endl;
	string findStr;
	cin >> findStr;

	if (uslStr.findItem(findStr) == true)
		cout << findStr << " is found in the list" << endl;
	else
		cout << findStr << " is not found in the list" << endl;

	uslStr.deleteItem("Ford");
	uslStr.printList();

	return 0;
}