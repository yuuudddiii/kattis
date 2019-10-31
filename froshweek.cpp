#include <bits/stdc++.h>

using namespace std;

void merge(vector<long long> &num, long long l, long long m, long long r, long long &count) {
	long long i, j, k;
	long long n1 = m-l+1;
	long long n2 = r-m;
	long long L[n1], R[n2];
	for (i = 0; i < n1; ++i)
		L[i] = (num[l+i]);
	for (j = 0; j < n2; ++j)
		R[j] = (num[m+1+j]);

	i = 0;
	j = 0;
	k = l;
	long long leftOver = n1;

	while(i< n1 && j <n2) {
		if (L[i] <= R[j]) {
			num[k] = L[i];
			i++;
			leftOver--;
		}
		else {
			count += leftOver;
			num[k] = R[j];
			j++;
		}
		k++;
	}
	while (i<n1) {
		num[k] = L[i];
		i++;
		k++;
	}
	while (j<n2) {
		num[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<long long> &num, long long l, long long r, long long &count) {
	if (l<r) {
		long long m = (l + r)/2;
		mergeSort(num, l,m, count);
		mergeSort(num, m+1, r, count);
		merge(num, l, m, r, count);
	}
}

int main() {
	long long n;
	cin >> n;
	long long count = 0;
	vector<long long> num(n);
	for (auto &i: num)
		cin >> i;
	mergeSort(num, 0, n-1, count);
	cout << count;
	return 0;
}