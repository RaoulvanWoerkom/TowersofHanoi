// TowersofHanoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ostream>
#include <iostream>
#include <locale>
#include <iomanip>
#include <list>

// List of Tower
int towers[3];

// Amount of Disks on first Tower
int amountDisks;

// Totally Build Myself :)
void buildTower()
{
	// Show quick how much disks each tower has
	std::cout << "[" << towers[0] << "]" << "[" << towers[1] << "]" << "[" << towers[2] << "]" << " \n\n ";

	// Iterate Towers
	for (int towerNumber = 0; towerNumber < 3; towerNumber++)
	{
		// Show Tower Number
		std::cout << " TOWER " << towerNumber + 1 << " \n ";

		// Iterate Tower Disks
		for (int diskNumber = 0; diskNumber < towers[towerNumber]; diskNumber++)
		{
			std::cout << " \n ";
			// Add space between each level
			for (int diskSize = 0; diskSize < (amountDisks - diskNumber) - 1; diskSize++)
			{
				std::cout << "  ";
			}

			// Foreach disk add more ===
			for (int diskSize = 0; diskSize < diskNumber + 1; diskSize++)
			{
				std::cout << "====";
			}
		}

		// Separator between towers
		std::cout << std::left << " \n - - - - - - - - - - -  \n\n ";
	}

	std::cout << " \n ";
}

// Totally Build Myself :)
void move(int n, int from, int to, int via) {
	if (n == 1) {
		std::cout << "Move disk from pole " << from << " to pole " << to << " \n " << std::endl;

		// Add and substract disks from Towers array
		towers[from - 1]--;
		towers[to - 1]++;

		// Visualize Tower
		buildTower();
	}
	else {

		// http://www.cs.cmu.edu/~cburch/survey/recurse/hanoiimpl.html
		// https://en.wikipedia.org/wiki/Tower_of_Hanoi
		// https://rosettacode.org/wiki/Towers_of_Hanoi

		// Recursion solution found on the internet
		move(n - 1, from, via, to);
		move(1, from, to, via);
		move(n - 1, via, to, from);
	}
}

// Totally Build Myself :)
void getUserInput(std::string value_name, int value_min, int value_max, int *value)
{
	// Ask for input while input is not given or does not meet requirements
	while (*value > value_max || *value < value_min)
	{
		std::cout << " Please enter a value for the " << value_name << "  between " << value_min << "  and " << value_max << ": ";
		std::cin >> *value;
	}
}

// Totally Build Myself :)
int main()
{
	getUserInput("Amount of Disks", 3, 100, &amountDisks);

	// Add Disks to first Tower
	towers[0] = amountDisks;

	// Visualize Tower
	std::cout << " \n ";
	buildTower();

	move(amountDisks, 1, 2, 3);
	printf("Solved like a motherfucker");
};
