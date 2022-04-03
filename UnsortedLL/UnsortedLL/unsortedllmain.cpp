#include "unsortedll.h"

int main()
{
	unsortedLL usl = unsortedLL();

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

	usl.deleteItem(9);
	usl.printList();

	unsortedLL usl2(usl);
	usl2.printList();

	unsortedLL usl3;
	
	usl3 = usl;
	usl3.printList();

	return 0;
}