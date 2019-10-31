#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

void addNumber(long number, priority_queue<long, vector<long>,greater<long> > & highers, priority_queue<long> & lowers) {
	( (lowers.empty()) || number < lowers.top()) ? lowers.push(number) : highers.push(number);

}

void balance(priority_queue<long, vector<long>,greater<long> > & highers, priority_queue<long> & lowers) {
	int lowersSize = lowers.size();
	int highersSize = highers.size();

	if (lowersSize != highersSize) {
		if (lowersSize - highersSize > 1) {
				highers.push(lowers.top());
				lowers.pop();
		
		} else if (highersSize - lowersSize > 1) {
				lowers.push(highers.top());
				highers.pop();
		}
	}

}

long getMedian(priority_queue<long, vector<long>,greater<long> > & highers, priority_queue<long> & lowers) {
	int lowersSize = lowers.size();
	int highersSize = highers.size();

	if (lowersSize == highersSize)
		return (lowers.top() + highers.top())/2;
	return (lowersSize > highersSize) ? lowers.top() : highers.top();
}


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	bool first = false;
	cin >> n;

	while (true) {
		int length;
		long num;
		cin >> length;
		vector<long> numbers;
		for (int i = 0; i < length; i++) {

			cin >> num;
			numbers.push_back(num);
		}

		priority_queue<long, vector<long>,greater<long> > highers;
		priority_queue<long> lowers;

		long median = 0;

		for (int i = 0; i < length; i++) {
			long number = numbers[i];
			addNumber(number, highers, lowers);
			balance(highers, lowers);
			median += getMedian(highers, lowers);
		}

		if (first)
			cout << endl;
		first = true;
		cout << median;
		--n;
		if (n == 0)
			break;

	}

	return 0;
}