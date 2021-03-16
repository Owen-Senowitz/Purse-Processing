// Authors: Owen Senowitz
// This program simulates a small coin purse

#include <iostream>
using namespace std;

// Create an enumeration data type called Coin
enum class Coin { penny = 1, nickel = 5, dime = 10, quarter = 25 };

const int MAXSIZE = 15;
const int SENTINEL = 0;

// Takes user input (1, 2, 3, 4) and converts it to a Coin
Coin ConvertToCoin(int x);

// Prints a word to the screen stating what the coin is
void PrintCoin(Coin x);

int main()
{
	// Main program code here
	Coin purse[MAXSIZE];

	int value = 1;
	int i = 0;
	int cent = 0;

	cout << "Deposit coins into purse. Enter:\n";
	cout << "1 to deposit penny\n";
	cout << "2 to deposit nickel\n";
	cout << "3 to deposit dime\n";
	cout << "4 to deposit quarter\n";
	cout << SENTINEL << " to stop\n";
	cout << "\n";

	while ((value != SENTINEL) && (i != MAXSIZE)) {

		cout << "? ";
		cin >> value;
		if (value > 0) {
			purse[i] = ConvertToCoin(value);
			cent += int(purse[i]);
		}

		i++;
	}

	cout << "\n";

	if (i == MAXSIZE) {
		cout << "\nThe purse is full" << endl;
	}

	cout << "{ ";

	for (int conv = 0; conv < i; conv++) {
		PrintCoin(purse[conv]);
	}

	cout << "}";

	cout << "\n";

	printf("Total purse value: $%d.%02d", cent / 100, cent % 100);
	cout << "\n";

	return 0;
}

Coin ConvertToCoin(int x)
{
	if (x == 4) {
		return Coin::quarter;
	}
	else if (x == 3) {
		return Coin::dime;
	}
	else if (x == 2) {
		return Coin::nickel;
	}
	else if (x == 1) {
		return Coin::penny;
	}
}

void PrintCoin(Coin x)
{
	switch (x)
	{
	case Coin::penny:
		cout << "penny ";
		break;

	case Coin::nickel:
		cout << "nickel ";
		break;

	case Coin::dime:
		cout << "dime ";
		break;

	case Coin::quarter:
		cout << "quarter ";
		break;
	}
}