#include "StackArrayT.h"
#include "QueArrT.h"

bool palendromeTest(string test)
{

	QueArrT<char> palq = QueArrT<char>(test.length() + 1);
	StackArrayT<char> pals = StackArrayT<char>(test.length() + 1);
	int letters = 0;

	for (int i = 0; i < test.length(); i++)
	{
		if (isalpha(test[i]))
		{
			palq.enque(tolower(test[i]));
			pals.push(tolower(test[i]));
			letters++;
		}
		
	}
	cout << letters << endl;

	char forward;
	char backward;

	for (int i = 0; i < letters; i++)
	{
		palq.deque(forward);
		pals.pop(backward);
		
		if (forward != backward)
			return false;
	}

	return true;
}

int main()
{
	string test;

	test = "Do good? I? No. Evil anon, I deliver. I maim nine more hero men in Saginaw. Sanitary sword a-tuck Carol, I! Lo, rack, cut a drowsy rat in Aswan. I gas nine more hero men in Miami. Reviled, I? No, Na. Live on I do. O' God!";

	if (palendromeTest(test) == true)
		cout << "This is a palendrome." << endl;
	else
		cout << "This is not a palendrome." << endl;

	return 0;
}