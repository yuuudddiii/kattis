#include <bits/stdc++.h>

using namespace std;
struct sortDesc {
	bool operator()(const int &lhs, const int &rhs) const {
		return lhs>rhs;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	unordered_map<string, pair<long long, int>> database; // Name , id, infection level;
	map<int, map<long long, string>, sortDesc> pq; // infection level, id, name

	int choice, infectionLevel, updateInfection;
	string name;
	long long N; cin >> N;
	long long id = 0;

	for (long long i = 0; i < N; ++i)
	{
		cin >> choice;
		switch(choice)
		{
			case 0:
			{
				cin >> name >> infectionLevel;
				database.insert(database.end(), {name, make_pair(id, infectionLevel)});
				pq[infectionLevel].insert(make_pair(id,name));
				id++;
				break;
			}
			
			case 1:
			{
				cin >> name >> updateInfection;
				long long tempID = database[name].first;
				int tempInfection = database[name].second;
				pq[tempInfection].erase(tempID);
				if (pq[tempInfection].empty())
					pq.erase(tempInfection);
				pq[tempInfection+updateInfection].insert(make_pair(tempID,name));
				database[name].second += updateInfection;				
				break;
			}
			case 2:
			{
				cin >> name;
				long long tempID = database[name].first;
				int tempInfection = database[name].second;
				pq[tempInfection].erase(tempID);
				if (pq[tempInfection].empty())
					pq.erase(tempInfection);
				database.erase(name);				
				break;
			}
			case 3:
			{
				auto it = pq.begin();
				if (!database.empty())
					cout << it->second.begin()->second << endl;
				else
					cout << "The clinic is empty" << endl;
				break;
			}
		}

	}
	// for (auto i: database)
	// 	cout << i.first << "\t" << get<0>(i.second) << "\t" << get<1>(i.second) << endl;
	return 0;
}