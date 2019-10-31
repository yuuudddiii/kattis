#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string num;
		cin >> num;
		int length = num.size();
		int sum = 0;
		int count = 0;		
		for (int k = length-1; k >=0; --k) {
			int comp = num[k] - '0';
			if (count & 1) {
				if ((comp <<= 1) >= 10)
					comp -= 9;
			}
			sum+= comp;
			count++;
		}
		if (sum%10 == 0) {
			cout << "PASS" << endl;
		} else {
			cout << "FAIL" << endl;
		}
	}
	return 0;
}