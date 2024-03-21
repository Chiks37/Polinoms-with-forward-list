#include "TList.h"

int rnd()
{
	return rand() % 1000;
}

void main()
{

	int coef, xdeg, ydeg, zdeg, ans;
	TList firstList;
	do
	{
		std::cout << "Entering first polinom...\n";

		std::cout << "Enter coefficient >> ";
		std::cin >> coef;

		std::cout << "Enter x degree >> ";
		std::cin >> xdeg;

		std::cout << "Enter y degree >> ";
		std::cin >> ydeg;

		std::cout << "Enter z degree >> ";
		std::cin >> zdeg;

		firstList.add(coef, xdeg * 100 + ydeg * 10 + zdeg);

		std::cout << "Wanna continue?(0 to stop) >> ";
		std::cin >> ans;

	} while (ans);

	TList secondList;
	do
	{
		std::cout << "Entering Second polinom...\n";

		std::cout << "Enter coefficient >> ";
		std::cin >> coef;

		std::cout << "Enter x degree >> ";
		std::cin >> xdeg;

		std::cout << "Enter y degree >> ";
		std::cin >> ydeg;

		std::cout << "Enter z degree >> ";
		std::cin >> zdeg;

		secondList.add(coef, xdeg * 100 + ydeg * 10 + zdeg);

		std::cout << "Wanna continue?(0 to stop) >> ";
		std::cin >> ans;

	} while (ans);

	std::cout << "\nFirst:\n";
	//TList firstList;
	firstList.add(3, 222);
	firstList.add(5, 555);
	firstList.add(1, 111);
	firstList.print();

	std::cout << "\nSecond:\n";
	//TList secondList;
	secondList.add(4, 444);
	secondList.add(3, 310);
	secondList.add(-1, 111);
	secondList.print();

	std::cout << "\nSum1; first; second:\n";
	TList sumList = firstList + secondList;
	sumList.print();
	firstList.print();
	secondList.print();

	std::cout << "\nSum2; first; second:\n";
	firstList.quickSum(secondList);
	firstList.print();
	secondList.print();
}