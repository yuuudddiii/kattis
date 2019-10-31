#include <bits/stdc++.h>

using namespace std;

void tokenise(string line, queue<string> &tokens) { 
      
      
    // stringstream class check1 
    stringstream check1(line); 
      
    string intermediate; 
      	
    // Tokenizing w.r.t. space ' ' 
    while(getline(check1, intermediate, ' ')) //Change here what u want to tokenise
    { 
        tokens.push(intermediate); 
    } 
}

int main() {
	int n, throws; cin >> n >> throws;
	string temp;
	cin.ignore(); getline(cin, temp);
	queue<string> instructions;
	stack<string> history;
	tokenise(temp, instructions);

	list<int> students(n);
	int count = 0;
	for (auto &i: students)
		i = count++;

	auto it = students.begin();

	while (!instructions.empty())  {
		int num = 0;
		// Undo operation
		if (instructions.front() == "undo") {
			instructions.pop();
			for (int k = 0; k < stoi(instructions.front()); ++k) {
				num += -1 * stoi(history.top());
				history.pop();
			}
			instructions.pop();
		}
		else {
			num += stoi(instructions.front());
			history.push(instructions.front());
			instructions.pop();
		}
		while (num != 0) {
			if (num < 0) {
				if (it == students.begin()) it = students.end();
				it--;
				num++;
			}
			else {
				it++;
				if (it == students.end()) it = students.begin();
				num--;
			}
		}
	}
	cout << *it;

	return 0;
}


// I use a list to store the data
// A queue to store the operations
// A stack to keep the history of operations

