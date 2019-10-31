#include <iostream>
#include <algorithm>

using namespace std;

void zeroless(int arr[]) {
	for (int i = 0; i < 4; ++i) {
		if (arr[i] == 0) {
			for (int j = i + 1; j < 4; ++j) {
				if (arr[j] != 0) {
					arr[i] = arr[j];
					arr[j] = 0;
					j = 4;
				}
			}
		}
	}
}

void sum(int arr[]) {
	for (int i = 1; i < 4; ++i) {
		if (arr[i-1] == arr[i]) {
			arr[i-1] *= 2;
			arr[i] = 0;
		}
	}
}

int main() {
	int board[4][4], temp[4][4], dir;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> board[i][j];
		}
	}

	cin >> dir;

	switch (dir) {
		case 0: // Left
			for (int i = 0; i < 4; ++i)
			{
				zeroless(board[i]);
				sum(board[i]);
				zeroless(board[i]);
			}
			break;
		case 1: // Up
			for (int i = 0; i < 4; ++i) // Transform columns to rows and store in temporary array to solve it like case 0..
			{
				for (int j = 0; j < 4; ++j) {
					temp[i][j] = board[j][i];
				}
				zeroless(temp[i]);
				sum(temp[i]);
				zeroless(temp[i]);
			}
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
					board[i][j] = temp[j][i];
			}
			break;
		case 2: // Right
			for (int i = 0; i < 4; ++i)
			{
				reverse(board[i], board[i]+4); // To reverse the order and solve it like case 0..
				zeroless(board[i]);
				sum(board[i]);
				zeroless(board[i]);
				reverse(board[i], board[i]+4);

			}
			break;
		case 3: // Down
			for (int i = 0; i < 4; ++i) // Transform columns to rows and store in temporary array to solve it like case 0..
			{
				for (int j = 0; j < 4; ++j) {
					temp[i][j] = board[j][i];
				}
				reverse(temp[i], temp[i]+4); // To reverse the order and solve it like case 0..
				zeroless(temp[i]);
				sum(temp[i]);
				zeroless(temp[i]);
				reverse(temp[i], temp[i]+4);
			}
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
					board[i][j] = temp[j][i];

			}			
			break;
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}