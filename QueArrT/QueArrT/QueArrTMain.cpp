#include "QueArrT.h"

int main()
{
	QueArrT<int> qai = QueArrT<int>();
	qai.printQue();
	qai.enque(5);
	qai.enque(3);
	qai.enque(99);
	qai.enque(16);

	qai.printQue();
	int rmi = 0;
	qai.deque(rmi);

	cout << rmi << " has been removed from the queue" << endl;

	qai.printQue();

	return 0;
}