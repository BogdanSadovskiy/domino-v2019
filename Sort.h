using namespace std;

void sortStone(stone* stonePlayer, int P) {
	int sum = 0;
	int a = 1;
	for (int i = 0; i < P; i++) {
		sum = stonePlayer[i].st1 + stonePlayer[i].st2;
		for (int j = i + 1; j < P; j++) {
			if (sum > (stonePlayer[j].st1 + stonePlayer[j].st2)) {
				int n = stonePlayer[i].st1;
				stonePlayer[i].st1 = stonePlayer[j].st1;
				stonePlayer[j].st1 = n;
				n = stonePlayer[i].st2;
				stonePlayer[i].st2 = stonePlayer[j].st2;
				stonePlayer[j].st2 = n;
				i--;
				break;
			}
		}
	}
}
void sortBoard(stone* onBoard, int B) {
	if (B > 1) {
		if (onBoard[0].st2 != onBoard[1].st1) {
			int n = onBoard[0].st2;
			onBoard[0].st2 = onBoard[0].st1;
			onBoard[0].st1 = n;
		}

		if (onBoard[B - 1].st1 != onBoard[B - 2].st2) {
			int n = onBoard[B - 1].st2;
			onBoard[B - 1].st2 = onBoard[B - 1].st1;
			onBoard[B - 1].st1 = n;
		}

	}
}
