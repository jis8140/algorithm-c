#include<iostream>
#include<list>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  char command;
  list<char> L;
  string str;
  int N;
  cin >> str >> N;
  for (auto s : str) L.push_back(s);
  list<char>::iterator cursor = L.end();
  for (int i = 0; i < N; i++) {
    cin >> command;
    if (command == 'L') {
      if (cursor != L.begin()) cursor--;
    } else if (command == 'D'){
      if (cursor != L.end()) cursor++;
    } else if (command == 'B') {
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
    } else {
      char x;
      cin >> x;

      L.insert(cursor, x);
    }
  }

  for (auto a : L) cout << a;
}