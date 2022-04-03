#include "unsortedLLMT.h"

int main()
{
	unsortedLLMT cur = unsortedLLMT();
	cur.putItem(3);
	cur.putItem(10);
	cur.putItem(12);
	cur.putItem(5);
	cur.putItem(8);
	cur.putItem(15);
	cur.putItem(18);

	cur.printNodes();

	cur.deleteNminus1thNode();

	cur.printNodes();

	return 0;
}