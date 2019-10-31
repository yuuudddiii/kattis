#include <iostream>
#include <algorithm>

using namespace std;

string addNum(string str1, string str2) {
	if (str1.length() > str2.length())
		swap(str1,str2);
	string str = "";

	int l1 = str1.length(), l2 = str2.length();
	int diff = l2 - l1;

	int carry = 0;

	for (int i = l1-1; i>=0; --i) {
		int sum = ((str1[i]-'0') + str2[i+diff]-'0' + carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	for (int i=diff-1; i>=0; --i){
		int sum = (str2[i]-'0') + carry;
		str.push_back(sum%10 +'0');
		carry = sum/10;
	}

	if (carry)
		str.push_back(carry+'0');

	reverse(str.begin(),str.end());
	return str;
}
int main() {
    
    string a, b;
    cin >> a >> b;
    cout << addNum(a,b);
    return 0;
}