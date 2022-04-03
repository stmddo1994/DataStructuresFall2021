#include "StackArrayT.h"

int main()
{
	StackArrayT<int> sai = StackArrayT<int>();

	sai.printStack();
	sai.push(9);
	sai.push(999);
	sai.printStack();
	sai.push(99);

	sai.printStack();

	sai.pop();
	sai.printStack();

	sai.push(9999);
	sai.printStack();

	//operators work like push and pop
	sai.operator+(333);
	sai.printStack();
	sai.operator-();
	sai.printStack();

	sai.pop();
	sai.printStack();

	sai.pop();
	sai.pop();
	sai.printStack();

	StackArrayT<string> sas = StackArrayT<string>();
	sas.printStack();
	sas.push("apple");
	sas.push("999");
	sas.printStack();
	sas.push("John");

	sas.printStack();

	sas.pop();
	sas.printStack();

	sas.push("orange");
	sas.printStack();

	sas.pop();
	sas.printStack();

	sas.pop();
	sas.pop();
	sas.printStack();
}