#include <bits/stdc++.h>

using namespace std;

int nav(vector<vector<char>> &b, int x, int y) {
	int count = 0;
	if (b[x][y] == 'X' || b[x][y] == '#')
		return count;

	if (b[x][y] == 'G') count = 1;

	b[x][y] = 'X';

	if (b[x+1][y] == 'T' || b[x-1][y] == 'T' || b[x][y+1] == 'T' || b[x][y-1] == 'T')	
	{
		return count;
	}
	return count + nav(b, x, y+1) + nav(b,x, y-1) + nav(b, x-1, y) + nav(b,x+1, y);
	
	
}

int main() {
	int W, H; cin >> W >> H; cin.ignore();
	vector<vector<char>> board(H, vector<char>(W));
	int x, y;
	for (int i = 0; i < H; ++i) {
		string temp;
		getline(cin, temp);
		for (int j = 0; j < W; ++j) {
			board[i][j] = temp[j];
			if (temp[j] == 'P')
			{
				x = i; y = j;
			}
		}
	}
	cout << nav(board, x, y) << endl;
	return 0;
}