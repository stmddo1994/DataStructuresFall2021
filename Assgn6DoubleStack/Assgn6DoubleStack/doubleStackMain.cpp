//File: StackDoubleMain.h
//Project: CSIS 3400 Assignment 6
//Author: Mathew Doty
//Version: 1.1 Oct 16, 2021

#include "doubleStackInt.h"

int main()
{
	doubleStackComp test = doubleStackComp();
	test.push(27);
	test.push(426);

	test.printStacks();

	test.push(832);
	test.push(644);
	test.push(444);
	test.push(923);
	test.push(289);
	test.push(1023);
	test.push(367);
	test.push(330);
	test.push(923);
	test.push(20);
	test.push(1003);
	test.push(1200);
	test.push(83);
	test.push(4);
	test.push(776);
	test.push(102);
	test.push(887);
	test.push(48);
	test.push(98);

	test.printStacks();

	test.pop1();
	test.pop2();
	test.pop2();

	test.printStacks();

	return 0;
}