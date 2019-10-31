#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N; cin.ignore();
    bool notFirst = false;
    while (N--) {
        set<char> letters;
        char myLetters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        set<char> full (myLetters, myLetters+26);
        string temp;
        getline(cin,temp);
        for (int i = 0; i < static_cast<int>(temp.size()); ++i) { 
            if (isalpha(temp[i])) 
                letters.insert(tolower(temp[i]));
        }
        if (notFirst)
            cout << "\n";
        notFirst = true;
        if (static_cast<int>(letters.size()) == 26) {
            cout << "pangram";
        }
        else {
           set<char> result;
            set_difference(full.begin(), full.end(), letters.begin(), letters.end(),
 inserter(result, result.end()));
            cout << "missing ";
            for (auto &i: result)
                cout << i;
        }
    }
    return 0;
}
