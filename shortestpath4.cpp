#include <bits/stdc++.h>
/******************************************
* AUTHOR : TERRY TAY *
* NICK : PUPU *
* INSTITUTION : NATIONAL UNIVERSITY OF SINGAPORE *
******************************************/
using namespace std;
typedef tuple<int, int, int> pr;
#define INF INT_MAX

class prioritize{public: bool operator ()(pr &p1 ,pr &p2){return get<0>(p1) > get<0>(p2);}};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int TC, n, index, k, s, d, V; cin >> TC;
	while (TC--) {
		cin >> V;
		vector<vector<pair<int,int>>> graph(V, vector<pair<int,int>>()); //Adj list of V nodes initialised
		for (auto &i: graph) {
			cin >> n;
			while(n--){
				cin >> index >> k;
				i.emplace_back(index, k);
			}
		}
		int Q; cin >> Q;
		for (int i = 0; i < Q; ++i) {
			int k, ans = -1;
			cin >> s >> d >> k;
			priority_queue<pr, vector<pr>, prioritize> toProc; // Prioritise weight

			vector<vector<int>> kth(k+1, vector<int>(V,INF)); // Aggregated weight of node at 1<=junction<=k

			kth[1][s] = 0;
			toProc.push(tuple(0, 1, s)); // (Weight, junc, node)
			while(!toProc.empty()) {
				auto [cW, cJ, cN] = toProc.top(); // c++17 feature
				// cW: weight, cJ: junction, cN: node
				if (cN == d) { //If node is destination node
					ans = cW;
					break;
				}
				toProc.pop();
				if (cJ < k) //Only add node if the layer of nodes coming next is <= k
					for (auto &item: graph[cN]) // For each neighbour in the current node
						/// Comparing neighbour's weight with (current aggregate weight + to traverse weight)
						if (kth[cJ+1][item.first] > kth[cJ][cN] + item.second) { 
							kth[cJ+1][item.first] = kth[cJ][cN] + item.second;
							toProc.push(tuple(kth[cJ+1][item.first], cJ+1, item.first));
							// Push to pq the node with an increase in junction and new agg weight
						}
			}
			cout << ans << "\n";
		}
	if (TC)
		cout << "\n";
	}
	return 0;
}
