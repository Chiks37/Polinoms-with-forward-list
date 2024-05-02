#include "TList.h"

int rnd()
{
	return rand() % 1000;
}

void main()
{

	int coef, xdeg, ydeg, zdeg, ans;
	TList firstList;
	std::cout << "Entering first polinom...\n";
	do
	{
		std::cout << "Enter coefficient >> ";
		std::cin >> coef;

		if (coef != 0)
		{
			std::cout << "Enter x degree >> ";
			std::cin >> xdeg;

			if (xdeg >= 0 && xdeg <= 9)
			{
				std::cout << "Enter y degree >> ";
				std::cin >> ydeg;

				if (ydeg >= 0 && ydeg <= 9)
				{
					std::cout << "Enter z degree >> ";
					std::cin >> zdeg;

					if (zdeg >= 0 && zdeg <= 9)
					{
						firstList.add(coef, xdeg * 100 + ydeg * 10 + zdeg);
					}
					else
					{
						std::cout << "Wrong z degree.\n";
					}
				}
				else
				{
					std::cout << "Wrong y degree.\n";
				}
			}
			else
			{
				std::cout << "Wrong x degree.\n";
			}
		}
		else
		{
			std::cout << "Wrong coefficient.\n";
		}

		std::cout << "Wanna continue entering?(0 to stop) >> ";
		std::cin >> ans;

	} while (ans);

	std::cout << "\nEntering Second polinom...\n";
	TList secondList;
	do
	{
		std::cout << "Enter coefficient >> ";
		std::cin >> coef;

		if (coef != 0)
		{
			std::cout << "Enter x degree >> ";
			std::cin >> xdeg;

			if (xdeg >= 0 && xdeg <= 9)
			{
				std::cout << "Enter y degree >> ";
				std::cin >> ydeg;

				if (ydeg >= 0 && ydeg <= 9)
				{
					std::cout << "Enter z degree >> ";
					std::cin >> zdeg;

					if (zdeg >= 0 && zdeg <= 9)
					{
						secondList.add(coef, xdeg * 100 + ydeg * 10 + zdeg);
					}
					else
					{
						std::cout << "Wrong z degree.\n";
					}
				}
				else
				{
					std::cout << "Wrong y degree.\n";
				}
			}
			else
			{
				std::cout << "Wrong x degree.\n";
			}
		}
		else
		{
			std::cout << "Wrong coefficient.\n";
		}

		std::cout << "Wanna continue entering?(0 to stop) >> ";
		std::cin >> ans;

	} while (ans);

	std::cout << "\nFirst:\n";
	firstList.print();

	std::cout << "\nSecond:\n";
	secondList.print();

	std::cout << "\nSum1:\n";
	TList sumList = firstList + secondList;
	sumList.print();
	std::cout << "\nFirst:\n";
	firstList.print();
	std::cout << "\nSecond:\n";
	secondList.print();

	std::cout << "\nSum2.\n";
	firstList.quickSum(secondList);
	std::cout << "First:\n";
	firstList.print();
	std::cout << "\nSecond:\n";
	secondList.print();
}