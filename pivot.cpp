#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> num(n);
	vector<int> lR;
	vector<int> rL;

	for (auto &i: num)
		cin >> i;

	lR.push_back(num[0]);
	rL.push_back(num[n-1]);
	int j = 0;

	for (int i = 1; i < n; ++i, j++) {
		lR[i-1] > num[i] ? lR.push_back(lR[i-1]) : lR.push_back(num[i]);
		rL[j] < num[n-i-1] ? rL.push_back(rL[j]) : rL.push_back(num[n-i-1]);
	}

	int count = 0;
	for (j = 0; j < n; ++j)
		if (num[j]>=lR[j] && num[j]<=rL[n-j-1])
			count++;
	cout << count;
	return 0;
}

