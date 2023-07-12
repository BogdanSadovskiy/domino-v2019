using namespace std;
#include <iostream>
#include <Windows.h>
#include "Sort.h"
#include "PlayerGameplay.h"
#include "CompGameplay.h"
int left = 0;
int rigth = 0;
int comp = 1;
int player = 2;


void result(stone* stonePlayer, int  P, stone* stoneComputer, int  C, int& Padd, int& Cadd) {
	for (int i = 0; i < P; i++) {
		Padd += stonePlayer[i].st1 + stonePlayer[i].st2;
	}
	for (int i = 0; i < C; i++) {
		Cadd += stoneComputer[i].st1 + stoneComputer[i].st2;
	}
}

bool whoIsFirst(stone*& stonePlayer, int& P, stone*& stoneComputer, int& C) {
	int MAXplayer = 0;			//determining who will step first
	int iplayer = 0;
	int icomp = 0;
	int MAXComp = 0;
	for (int i = 0; i < P; i++) {
		if ((stonePlayer[i].st1 == stonePlayer[i].st2) && stonePlayer[i].st1 > MAXplayer) {
			MAXplayer = stonePlayer[i].st1;
			iplayer = i;
		}
		if ((stoneComputer[i].st1 == stoneComputer[i].st2) && stoneComputer[i].st1 > MAXComp) {
			MAXComp = stoneComputer[i].st1;
			icomp = i;
		}
	}
	whoIsBigger(MAXplayer, MAXComp, iplayer, icomp);
	if (MAXplayer > MAXComp) {
		cout << "You are going first\n\n";
		return true;
	}
	else {
		cout << "Computer are going first\n\n";
		return false;
	}
}
void changePlayer(int& current) {
	if (current == player) {
		current = comp;
		cout << "\nComputers turn\n";
	}
	else {
		current = player;
		cout << "\nPlayers turn\n";
	}
}

int whatIsStr(string in, int& n1, int& n2) {
	int size = in.length();
	if (size > 2) {
		return	-1;				//determining of numbers
	}						// for ex: you inputted "14" in string;
	int number = 0;			// now we have "14" as an int
	int m = 1;

	for (int i = 0; i < 2; i++) {
		if ((int)in[i] < 48 || (int)in[i] > 54) {

			return -1;
		}
		if (i == 0) {
			n1 = ((int)in[i] - 48);
		}
		else {
			n2 = ((int)in[i] - 48);
			return 1;
		}
	}
	return -1;
}
bool canIStep(stone* onBoard, int B, stone* stonePlayer, int P) {
	//func, that determinate, there is some stone for next step or not in players hands
	if (B == 0) {
		return true;
	}
	int first = onBoard[0].st1;
	int last = onBoard[B - 1].st2;
	for (int i = 0; i < P; i++) {
		if (stonePlayer[i].st1 == first || stonePlayer[i].st2 == first) {
			return true;
		}
		if (stonePlayer[i].st1 == last || stonePlayer[i].st2 == last) {
			return true;
		}
	}
	return false;
}
bool isAvailable(stone* onBoard, int B, int n1, int n2) {
	if (n1 == onBoard[0].st1 || n1 == onBoard[B - 1].st2) {
		
		return true;
	}
	if (n2 == onBoard[0].st1 || n2 == onBoard[B - 1].st2) {
		
		return true;
	}
	return false;
}
int sideOnBoard(stone* onBoard, int B, int n1, int n2) {
	int left = 0;
	int right = 0;
	if (B == 0) {
		return 1;
	}
	if (n1 == onBoard[0].st1 || n2 == onBoard[0].st1) {
		left++;
	}
	if (n1 == onBoard[B - 1].st2 || n2 == onBoard[B - 1].st2) {
		right++;
	}
	if (right == 1 && left == 1) {
		return 3; // both sides
	}
	else if (right == 1 && left == 0) {
		return 2; // right side
	}
	else {
		return 1; // left side
	}
}

void takeStoneFromStash(stone*& onBoard, int& B, stone*& stonePlayer, int& P) {
	int num = rand() % B;
	stone* newstonePlayer = new stone[P + 1];
	for (int i = 0; i < P; i++) {
		newstonePlayer[i] = stonePlayer[i];
	}
	newstonePlayer[P] = onBoard[num];
	P++;
	delete[] stonePlayer;
	stonePlayer = newstonePlayer;
	for (int i = num; i < B - 1; i++) {
		onBoard[i] = onBoard[i + 1];
	}
	B--;
	cout << " taking the stone from stash\n";
}
void layStoneOnBoard(stone*& onBoard, int& B, stone*& stonePlayer, int& P, int  n1, int n2, int side) {
	stone* newBoard = new stone[B + 1];
	int Pdel = 0;
	for (int i = 0; i < P; i++) {
		if (n1 == stonePlayer[i].st1 && n2 == stonePlayer[i].st2) {
			Pdel = i;
			break;
		}
		if (n1 == stonePlayer[i].st2 && n2 == stonePlayer[i].st1) {
			Pdel = i;
			break;
		}
	}
	if (side == 1) {
		newBoard[0] = stonePlayer[Pdel];
		int k = 0;
		for (int i = 1; i < B + 1; i++) {
			newBoard[i] = onBoard[k];
			k++;
		}
	}
	else if (side == 2) {
		newBoard[B] = stonePlayer[Pdel];
		for (int i = 0; i < B; i++) {
			newBoard[i] = onBoard[i];
		}
	}
	B++;
	delete[]onBoard;
	onBoard = newBoard;
	stone* newP = new stone[P - 1];
	int j = 0;
	for (int i = 0; i < P - 1; i++) {
		if (i == Pdel) {
			j++;
		}
		newP[i] = stonePlayer[j];
		j++;
	}
	P--;
	delete[] stonePlayer;
	stonePlayer = newP;
}


bool play(stone*& allstone, int& all, stone*& stonePlayer, int& P, stone*& stoneComputer, int& C) {
	int endGame = 66;

	stone first;
	first.st1 = 0;
	first.st2 = 0;
	int current = comp;
	int B = 0;
	stone* onBoard = new stone[B];
	int board_f_el = 0;

	sortStone(stonePlayer, P);

	if (whoIsFirst(stonePlayer, P, stoneComputer, C) == true) {
		yourStones(stonePlayer, P);
		Sleep(2500);
		current = player;
		system("CLS");

	}
	else {
		current = comp;
	}
	bool set = true;

	while (set) {
	Move:

		if (B >= 1) {
			system("CLS");
			sortBoard(onBoard, B);
			boardStoneStones(onBoard, B, first);
			yourStones(stonePlayer, P);

		}

		sortStone(stonePlayer, P);

		if (B == 0) {
			yourStones(stonePlayer, P);
		}
		if (current == player) {
			if (canIStep(onBoard, B, stonePlayer, P) == false && all == 0) {
				return endGame;
			}
			if (canIStep(onBoard, B, stonePlayer, P) == false) {
				cout << "You are";
				takeStoneFromStash(allstone, all, stonePlayer, P);
				goto Move;
			}
			if (playerGame(onBoard, B, stonePlayer, P, first) == false) {
				return false;
			}
			if (P == 0) {
				return endGame;
			}
			changePlayer(current);

		}


		else if (current == comp) {

			if (B > 1) {
				sortBoard(onBoard, B);
				boardStoneStones(onBoard, B, first);
			}

			if (canIStep(onBoard, B, stoneComputer, C) == false && all == 0) {
				return endGame;
			}

			if (canIStep(onBoard, B, stoneComputer, C) == false) {
				cout << "Computer ";
				takeStoneFromStash(allstone, all, stoneComputer, C);
				goto Move;
			}
			Sleep(1500);
			if (CompGame(onBoard, B, stoneComputer, C, first) == false) {
				return false;
			}

			if (P == 0) {
				return endGame;
			}
			changePlayer(current);
		}
	}
	return endGame;
}