#include <iostream>
using namespace std;
int getDegree(int,int,int,int);
bool checkLast(int, int, int, int);

int main() {

    int initial, first, second, third;
    bool status = true;
    while (status) {
        cin >> initial >> first >> second >> third;
        if (checkLast(initial,first,second,third)) {
            cout << getDegree(initial,first,second,third) << endl;
        }
        else {
            status = false;
        }
    }
}
bool checkLast(int initial, int first, int second, int third) {
    if (!((initial != 0) || (first != 0) || (second != 0) || (third != 0)))
        return false;
    return true;

}
int getDegree(int initial, int first, int second, int third) {
   int oneRound = 360;
   int count = 0;

   count+= 2*oneRound;

   if (first > initial) {
    count+= ((40-first)+initial)*9;
   }
   else {
    count+= (initial-first)*9;
   }


   count+= oneRound;

   if (second < first) {
        count+= (40-first)*9;
        count+= second*9;
   }
   else {
        count+= (second-first)*9;
   }

   if (third > second) {
        count+= second*9;
        count+= (40-third)*9;
   }
   else {
        count+= (second-third)*9;
   }

    return count;
}
