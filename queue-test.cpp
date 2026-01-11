/* 
This file is complete, you don't need to change anything

queue_test.cpp
Author: CS 103 Course Staff
Description: Tests whether the Queue class is working.
Expected output:
true
false
3 1
true
2 2
1 4
true
*/

#include "queue.h"
#include <iostream>
using namespace std;

int main() {
   // create some locations;
   Location three_one, two_two, one_four;
   three_one.row = 3; three_one.col = 1;
   two_two.row = 2; two_two.col = 2;
   one_four.row = 1; one_four.col = 4;

   // create an Queue with max capacity 5
   Queue q;

   cout << boolalpha;
   cout << q.is_empty() << endl;           // true
   q.add_to_back(three_one);
   cout << q.is_empty() << endl;           // false
   Location loc = q.remove_from_front();
   cout << loc.row << " " << loc.col << endl; // 3 1
   cout << q.is_empty() << endl;           // false


   q.add_to_back(two_two);
   q.add_to_back(one_four);

   loc = q.remove_from_front();
   cout << loc.row << " " << loc.col << endl; // 2 2
   loc = q.remove_from_front();
   cout << loc.row << " " << loc.col << endl; // 1 4
   cout << q.is_empty() << endl;           // true
}
