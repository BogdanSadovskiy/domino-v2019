using namespace std;
#include <iostream>

bool canIStep(stone* onBoard, int B, stone* stonePlayer, int P);
void takeStoneFromStash(stone*& onBoard, int& B, stone*& stonePlayer, int& P);
int sideOnBoard(stone* onBoard, int B, int n1, int n2);
void layStoneOnBoard(stone*& onBoard, int& B, stone*& stonePlayer, int& P, int  n1, int n2, int side);

bool compChoose(stone* onBoard, int B, stone* stoneComputer, int C, int& iter) {
	if (B == 0) {
		iter = rand() % C;
		return true;
	}
	for (int i = 0; i < C; i++) {
		if (stoneComputer[i].st1 == onBoard[0].st1 || stoneComputer[i].st2 == onBoard[0].st1) {
			iter = i;
			return true;
		}
		else if (stoneComputer[i].st1 == onBoard[B - 1].st2 || stoneComputer[i].st2 == onBoard[B - 1].st2) {
			iter = i;
			return true;
		}
	}
	return false;
}


bool CompGame(stone*& onBoard, int& B, stone*& stoneComputer, int& C, stone& first) {
	int endGame = 66;
	const int left = 1;
	const int right = 2;
compgame:
	int iter = 0;
	if (compChoose(onBoard, B, stoneComputer, C, iter) == false) {
		takeStoneFromStash(onBoard, B, stoneComputer, C);
		goto compgame;
	}
	int n1 = stoneComputer[iter].st1; int n2 = stoneComputer[iter].st2;
	int num = sideOnBoard(onBoard, B, n1, n2);
	if (num == 3) {
		layStoneOnBoard(onBoard, B, stoneComputer, C, n1, n2, right);
	}

	else if (num == 2) {
		layStoneOnBoard(onBoard, B, stoneComputer, C, n1, n2, right);
	}
	else if (num == 1) {
		layStoneOnBoard(onBoard, B, stoneComputer, C, n1, n2, left);
	}
	if (B == 1) {
		first = onBoard[0];
	}
	return endGame;

}