#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> bricks;
	for (int i = 0; i < n; ++i) {
		int width;
		cin >> width;
		bricks.push_back(width);
	}
	bool success = true;
	for (int i = 0; i < h; ++i) {
		int sum = 0;
		while (sum<w) {
				sum+= bricks.at(0);
				bricks.erase(bricks.begin());
		}
		if (sum!=w)
			success = false;
	}
	cout << (success ? "YES" : "NO");
	return 0;
}