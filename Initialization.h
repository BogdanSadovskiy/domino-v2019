using namespace std;
#include <iostream>
#include <cstdlib>
struct stone {
	int st1;
	int st2;
};

void initializationStore(stone* allStone, int size) {
	int f = 0;
	int s = 0;
	for (int i = 0; i < size;) {
		s = f;
		while (s != 7)
		{
			allStone[i].st1 = f;
			allStone[i].st2 = s++;
			i++;
		}
		f++;
	}
}
void intitializationStone(stone*& allStone, int& size, stone*& player, int& P) {
	srand(time(NULL));
	for (int i = 0; i < 7; i++) {
		int num = rand() % size;
		player[i] = allStone[num];
		for (int j = num; j < size - 1; j++) {
			allStone[j] = allStone[j + 1];
		}
		size--;
	}
}
bool isDouble(stone* player, int P) {		// the both players have to get at least one stone with
	for (int i = 0; i < P; i++) {			// double number on it
		if (player[i].st1 == player[i].st2) {
			return true;
		}
	}
	return false;
}
