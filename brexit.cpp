#include <bits/stdc++.h>

using namespace std;
struct country {
	bool isRemoved = false;
	long curPartners = 0;
	long iniPartners = 0;
	vector<long> partners;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	long C, P, X, L; cin >> C >> P >> X >> L; --X; --L;
	long a, b;
	vector<country> data(C);
	for (long i = 0; i < P; ++i)
	{
		cin >> a >> b; --a; --b;
		data[a].iniPartners++; data[b].iniPartners++;
		data[a].curPartners++; data[b].curPartners++;
		data[a].partners.push_back(b); data[b].partners.push_back(a);
	}
	queue<long> toProc;
	data[L].isRemoved = true; 
	for (auto &i: data[L].partners) {
		data[i].curPartners--;
		toProc.push(i);
	}
	while (!toProc.empty()) {
		if (data[X].isRemoved == true) break;
		long index = toProc.front(); toProc.pop();
		if (data[index].isRemoved) continue;

		if (data[index].curPartners <= data[index].iniPartners/2) {
			data[index].isRemoved = true;
			for (auto &i: data[index].partners) {
				data[i].curPartners--;
				toProc.push(i);
			}
		}
	}
	cout << (data[X].isRemoved ? "leave" : "stay");
	return 0;
}