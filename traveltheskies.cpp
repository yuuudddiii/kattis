/* k: n.o. of airports, n: n.o. of days, m: n.o. of flights in the window.

m lines of u(src), v(dest), d(day of flight), z(capacity).

kn lines of a(which airport), b(the day), c(n.o. of customers boarding from that airport at that day).

optimal if all fully filled, if got non-full suboptimal */

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int k, n, m; cin >> k >> n >> m;
	int u, v, d, z;
	// Available flights
	vector<vector<vector<pair<int,int>>>> flights(n, vector<vector<pair<int,int>>>(k));
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> d >> z;
		--u; --d; --v;
		flights[d][u].emplace_back(v,z);
		 // On day d, flight available from u to v carrying z size
	}


	int arr[n][k]; // People flying at k airport on n day
	// memset(arr, 0, sizeof(arr));
	for (int i = 0; i < k*n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c; --a; --b;
		arr[b][a] = c; // The number of people boarding the plane at that airport on the day
	}

	vector<int> live(k,0); // Live update of people at the airport currently

	// Now let's start the day rolling:
	bool isOptimal = true;
	for (int i = 0; (i < n) && isOptimal; ++i){ // Each day iterating
		for (int j = 0; j < k; ++j) // Data regarding n.o. of people ready to board at each airport
			live[j] = arr[i][j];
		vector<int> dest = live;
		for (int j = 0; j < k; ++j)
		{
			for (auto &l : flights[i][j])
			{
				dest[j] -= l.second;
				if (dest[j] < 0) {
					isOptimal = false;
					break;
				}
				arr[i][l.first] += l.second;
			}
		}
		for (int j = 0; j < k; ++j)
			arr[i+1][j] += arr[i][j];

	}
	cout << (isOptimal ? "optimal" : "suboptimal");

	return 0;
}

