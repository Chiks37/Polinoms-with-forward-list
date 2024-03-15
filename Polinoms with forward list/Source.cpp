#include "TList.h"

int rnd()
{
	return rand() % 1000;
}

void main()
{
	std::cout << "\nfirst\n";
	TList firstList;
	firstList.print();

	std::cout << "\nsecond\n";
	TList secondList;
	secondList.add(3, 333);
	secondList.add(-2, 22);
	secondList.add(1, 1);
	secondList.print();

	std::cout << "\nsum; first; second\n";
	TList sumList = firstList + secondList;
	sumList.print();
	firstList.print();
	secondList.print();

	std::cout << "\nthird\n";
	TList thirdList;
	thirdList.print();

	std::cout << "\nsum; first; third\n";
	sumList = firstList + thirdList;
	sumList.print();
	firstList.print();
	thirdList.print();

	std::cout << "\nfourth\n";
	TList fourthList;
	secondList.add(-3, 333);
	secondList.add(2, 22);
	secondList.add(-1, 1);
	secondList.print();

	std::cout << "\nsum; second; fourth\n";
	sumList = secondList + fourthList;
	sumList.print();
	secondList.print();
	fourthList.print();
}