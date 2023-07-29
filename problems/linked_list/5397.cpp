#include<iostream>
#include<string>
#include<list>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  string str;
  cin >> N;

  while (N--) {
    cin >> str;
    list<char> L;
    list<char>::iterator t = L.begin();

    for (auto c : str) {
      if (c == '<') {
        if (t != L.begin()) t--; 
      } else if (c == '>'){
        if (t != L.end()) t++;
      } else if (c == '-') {
        if (t != L.begin()){
          t--;
          t = L.erase(t);
        }
      } else {
        if (t == L.end()) L.push_back(c);
        else L.insert(t, c);
      }
    }

    for (auto c : L) cout << c;
    cout << "\n";
  }
}