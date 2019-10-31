#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    int c, p, a, b;
    while (N--) {
        cin >> c >> p;
        for (int i = 0; i < p; ++i)
            cin >> a >> b;
        cout << c-1 << "\n";
    }
}