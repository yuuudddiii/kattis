#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, index = 0; cin >> n;
	vector<int> degree(10001, 0);
	vector<vector<int>> adj (10001);
	unordered_map<string, int> conv;

	for (int i = 0; i < n; ++i)
	{
		string c1, c2;
		cin >> c1 >> c2;
		if (conv.count(c1) == 0)
			conv[c1] = index++;
		if (conv.count(c2) == 0)
			conv[c2] = index++;
		int n1 = conv[c1], n2 = conv[c2];
		adj[n2].push_back(n1);
		degree[n1]++;
	}

	queue<int> rabak;
	for (int i = 0; i < index; ++i)
		if (degree[i] == 0)
			rabak.push(i);

	vector<bool> safe(index, true);
	while (!rabak.empty()) {
		int cur = rabak.front(); rabak.pop();
		safe[cur] = false;
		for (auto &i: adj[cur]) {
			degree[i]--;
			if (degree[i] == 0)
				rabak.push(i);
		}
	}
	string name;
	while (cin >> name) {
		index = conv[name];
		cout << name << " " << (safe[index] ? "safe" : "trapped") << endl;
	}
	return 0;
}

