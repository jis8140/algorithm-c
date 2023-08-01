#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue <int> Q;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  while (N--){
    string command;
    cin >> command;

    if (command == "push") {
      int x;
      cin >> x;
      Q.push(x);
    } else if (command == "front") {
      if (Q.empty()) cout << -1 << "\n";
      else cout << Q.front() << "\n";
    } else if (command == "back") {
      if (Q.empty()) cout << -1 << "\n";
      else cout << Q.back() << "\n";
    } else if (command == "size") {
      cout << Q.size() << "\n";
    } else if (command == "empty") {
      if (Q.empty()) cout << 1 << "\n";
      else cout << 0 << "\n";
    } else {
      if (Q.empty()) cout << -1 << "\n";
      else {
        cout << Q.front() << "\n";
        Q.pop();
      }
    }
  }
}