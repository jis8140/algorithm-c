#include <iostream>
#include <string>

using namespace std;

int alphabet[26];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  cin >> str;

  for (auto c : str) {
    alphabet[c - 'a']++;
  }

  for (int i = 0; i < 26; i++) cout << alphabet[i] << " ";
}