#include "Midterm3400Arrays.h"

int main()
{
	CSIS3400Arrays arr1 = CSIS3400Arrays();

	arr1.insert(100);
	arr1.insert(200);
	arr1.insert(300);
	arr1.insert(600);
	arr1.insert(900);
	arr1.insert(400);
	arr1.insert(500);
	arr1.insert(900);
	arr1.insert(800);
	arr1.insert(700);
	arr1.insert(800);
	arr1.display();

	arr1.stableRemove(900);
	arr1.display();

	return 0;

}