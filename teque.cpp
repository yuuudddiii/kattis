#include <bits/stdc++.h>

using namespace std;


class Teque {
private:
	deque<long> left;
	deque<long> right;
	long leftN = 0;
	long rightN = 0;
	

public:

	void balance() {
		if (leftN != rightN) {
			if (leftN - rightN > 1) {
				right.push_front(left.back());
				left.pop_back();
				leftN--;
				rightN++;
			}
			if (rightN - leftN > 1) {
				left.push_back(right.front());
				right.pop_front();
				leftN++;
				rightN--;
			}
		}

	}

	void push_back(long v) {
		if (left.empty()) {
			left.push_back(v);
			leftN++;
		} else {
			right.push_back(v);
			rightN++;
		}
		balance();
	}

	void push_front(long v) {
		left.push_front(v);
		leftN++;
		balance();
	}

	void push_middle(long v) {
		if (rightN > leftN) {
			left.push_back(right.front());
			right.pop_front();
			leftN++;
			rightN--;
		}
		right.push_front(v);
		rightN++;
	}
	void get(long index) {

		if (index >= leftN) {
			cout << right[index-leftN];
		}
		else {
			cout << left[index];
		}
	}

};



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	Teque T;
	long N, getCount;
	getCount = 0;
	cin >> N;
	cin.ignore();
	for (long i = 0; i < N; ++i) {
		string temp;
		getline(cin, temp);
		istringstream ss(temp);
		string word;
		ss >> word;
		if (word == "push_back") {
			ss >> word;
			T.push_back(stol(word));
			continue;
		}
		if (word == "push_front") {
			ss >> word;
			T.push_front(stol(word));
			continue;
		}
		if (word == "push_middle") {
			ss >> word;
			T.push_middle(stol(word));
			continue;
		}
		if (word == "get") {
			ss >> word;
			if (getCount != 0)
				cout << "\n";
			T.get(stol(word));
			getCount++;
			continue;
		}

	}
	return 0;
}