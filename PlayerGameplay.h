using namespace std;
#include <iostream>

bool canIStep(stone* onBoard, int B, stone* stonePlayer, int P);
void takeStoneFromStash(stone*& onBoard, int& B, stone*& stonePlayer, int& P);
int whatIsStr(string in, int& n1, int& n2);
bool isAvailable(stone* onBoard, int B, int n1, int n2);
int sideOnBoard(stone* onBoard, int B, int n1, int n2);
void layStoneOnBoard(stone*& onBoard, int& B, stone*& stonePlayer, int& P, int  n1, int n2, int side);

bool playerGame(stone*& onBoard, int& B, stone*& stonePlayer, int& P, stone& first) {
	int endGame = 66;
	const int left = 1;
	const int right = 2;
choose:
	cout << "Choose the stone\n";
	cout << "Exit (input \'e\'')\n";
	string in; cin >> in;
	if (in == "e" || in == "E") {
		return false;
	}
	int n1; int n2;
	if (whatIsStr(in, n1, n2) == -1) {
		cout << "Invalid date. Try again\n";
		goto choose;
	}
	if (B > 1) {
		if (isAvailable(onBoard, B, n1, n2) == false) {
			cerr << "You can not choose this stone\n";
			goto choose;
		}
	}
	if (sideOnBoard(onBoard, B, n1, n2) == 3) {
	LR:
		cout << "Left - 1\n";
		cout << "Right  - 2\n";
		cin >> in;
		if (in == "1" || in == "2");
		else {
			cerr << "Invalid. Try again\n";
			goto LR;
		}
		if (in == "1") {
			layStoneOnBoard(onBoard, B, stonePlayer, P, n1, n2, left);

		}
		else {
			layStoneOnBoard(onBoard, B, stonePlayer, P, n1, n2, right);
		}
	}

	else if (sideOnBoard(onBoard, B, n1, n2) == 2) {
		layStoneOnBoard(onBoard, B, stonePlayer, P, n1, n2, right);

	}
	else if (sideOnBoard(onBoard, B, n1, n2) == 1) {
		layStoneOnBoard(onBoard, B, stonePlayer, P, n1, n2, left);
	}
	if (B == 1) {
		first = onBoard[0];
	}
	return endGame;
}
