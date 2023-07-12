
using namespace std;
#include <iostream>
#include "Initialization.h"
#include "Print.h"
#include "gameplay.h"

void menu() {
	cout << "Play --- 1\n";
	cout << "Exit --- E\n";
}



int main()
{
theBeginning:
	int roundCounter = 1;
	int playerCounter = 0;
	int compCounter = 0;
	while (roundCounter <= 3) {
		if (roundCounter == 1) {
			menu();
			string in; cin >> in;
			cout << "Round " << roundCounter << endl;
			if (in == "1") { ; }
			else if (in == "E" || in == "e") {
				cout << "Bye\n";
				return 0;
			}
		}

		else {
			cout << "Round " << roundCounter << endl;
			cout << "Input anything to continue\n";
			cout << "Input 'E' to exit\n";
			string in; cin >> in;
			if (in == "e" || in == "E") {
				cout << "Bye\n";
				return 0;
			}
		}
	initialize:
		int all = 28;
		stone* allstone = new stone[all];

		int P = 7;
		int C = 7;
		stone* stonePlayer = new stone[P];
		stone* stoneComputer = new stone[C];

		initializationStore(allstone, all);

		intitializationStone(allstone, all, stonePlayer, P);
		intitializationStone(allstone, all, stoneComputer, P);

		if (isDouble(stonePlayer, P) == false || isDouble(stoneComputer, C) == false) {
			goto initialize;
		}
		if (play(allstone, all, stonePlayer, P, stoneComputer, C) == false) {
			cout << "Bye\n";
			return 0;
		}

		roundCounter++;
		int Padd = 0;
		int Cadd = 0;
		result(stonePlayer, P, stoneComputer, C, Padd, Cadd);

		if (Padd > Cadd) {
			cout << "Computer WIN this round\n";
			compCounter++;
		}
		else {
			cout << "You WIN this round\n";
			playerCounter++;
		}


	}
	if (playerCounter == 2) {

		goto theBeginning;
	}
	if (compCounter == 2) {

		goto theBeginning;

	}
}
