#pragma once
using namespace std;
#include <iostream>
#include <cstdlib>

void yourStones(stone* Stone, int size) {
	cout << "\n\n\n\n\tYour stones:\n";
	for (int i = 0; i < size; i++) {
		cout << "+-+  ";
	}
	cout << "\n";
	for (int i = 0; i < size; i++) {
		cout << "|" << Stone[i].st1 << "|  ";
	}
	cout << "\n";
	for (int i = 0; i < size; i++) {
		cout << "|" << Stone[i].st2 << "|  ";
	}
	cout << "\n";
	for (int i = 0; i < size; i++) {
		cout << "+-+  ";
	}
	cout << "\n";
}
void whoIsBigger(int MAXplayer, int MAXcomp, int iPlayer, int iComp) {
	cout << "\nComputer stone: \n";
	cout << "                +-+\n";
	cout << "                |" << MAXcomp << "|\n";
	cout << "                +-+\n";
	cout << "                |" << MAXcomp << "|\n";
	cout << "                +-+\n\n";
	cout << "Player stone:   \n";
	cout << "                +-+\n";
	cout << "                |" << MAXplayer << "|\n";
	cout << "                +-+\n";
	cout << "                |" << MAXplayer << "|\n";
	cout << "                +-+\n\n";
}


void boardStoneStones(stone* onBoard, int size, stone first) {
	cout << endl;
	int iter = 0;
	for (int i = 0; i < size; i++) {
		if (first.st1 == onBoard[i].st1 && first.st2 == onBoard[i].st2) {
			iter = i;
		}
	}


	for (int i = iter; i < size; i++) {
		cout << "+---+ ";
	}
	cout << endl;
	for (int i = iter; i < size; i++) {
		cout << "|" << onBoard[i].st1 << "|" << onBoard[i].st2 << "| ";
	}
	cout << endl;
	for (int i = iter; i < size; i++) {
		cout << "+---+ ";
	}
	cout << endl;

	for (int i = iter - 1; i >= 0; i--) {
		cout << "+-+\n";
		cout << "|" << onBoard[i].st2 << "|\n";
		cout << "+ +\n";
		cout << "|" << onBoard[i].st1 << "|\n";
		cout << "+-+\n";
	}
}