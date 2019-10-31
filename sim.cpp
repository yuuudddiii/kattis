#include <bits/stdc++.h>
using namespace std;

struct Node {
	char value;
	Node* next;
	Node* prev;
};

class myList {
private:
	Node* head;
	Node* tail;
	Node* cursor;
	long count = 0;
	bool needNewHead = false;

public:
	myList() {
		tail = NULL;
		head = NULL;
		cursor = head;
	}

	void mode(char v) {
		if ((v == '<')) { //Delete 
			if (count) {
				Node* temp = cursor;
				if (cursor->prev == NULL && cursor->next == NULL) { //Delete only element left
					if (!needNewHead) {
						head = NULL;
						tail = NULL;
						cursor = head;
					}
				}
				else if (cursor == head) { //Delete first element with elements remaining after
					if (!needNewHead) {
						cursor->next->prev = NULL;
						head = cursor->next;
						cursor = head;
						needNewHead = true;
					}
				}
				else if (cursor->next == NULL) { //Delete last element with elements remaining after
					cursor->prev->next = NULL;
					tail = cursor->prev;
					cursor = tail;
				}
				else {
					cursor->prev->next = cursor->next; //Delete any elements in between
					cursor->next->prev = cursor->prev;
					cursor = cursor->prev;
				}
				if (!needNewHead) {
					delete temp;
					count--;
				}
			}
		}
		else if ((v == '[')) { // Go to start
			if (count) {

				cursor = head;
				needNewHead = true;
			}
		}
		else if ((v == ']')) { // Go to end
			if (count) {
				cursor = tail;
				needNewHead = false;
			}
		}
		else {
			Node *vtx = new Node();
			vtx->value = v;
			if (head == NULL) {
				if (count == 0) { // First element
					vtx->next = NULL;
					vtx->prev = NULL;
					tail = vtx;
					head = vtx;
					cursor = vtx;
				}
			}
			else {
				if (needNewHead && (cursor == head)) { 	// Insert before head
					vtx->next = head;
					vtx->prev = NULL;
					head->prev = vtx;
					head = vtx;
					cursor = head;
					needNewHead = false;
				}
				else {
					vtx->next = cursor->next; // Insert other places
					if (vtx->next == NULL)
						tail = vtx;
					vtx->prev = cursor;
					cursor->next = vtx;
					cursor = vtx;
				}
				
				
			}
			count++;
		}
			
	}
	void print() {
		if (count != 0) {
			while (cursor->prev != NULL)
				cursor=cursor->prev;
			Node* temp1 = cursor;
			while (temp1 != NULL) {
				cout << temp1->value;
				temp1=temp1->next;
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N; cin >> N; cin.ignore();
	bool notFirst = false;
	while(N--) {
		myList L;
		string input;
		getline(cin, input);
		for (long i = 0; i < static_cast<long>(input.size()); ++i) {
			L.mode(input[i]);
		}
		if (notFirst)
			cout << "\n";
		L.print();
		notFirst = true;

	}
	return 0;
}