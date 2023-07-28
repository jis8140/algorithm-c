#include <iostream>
#include <string>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s1, s2;
  cin >> s1 >> s2;

  int alphabet[27] = {};
  for (auto s : s1) alphabet[s-'a']++;
  for (auto s : s2) alphabet[s-'a']--;

  int count = 0;
  for (int i = 0; i < 27; i++) count += abs(alphabet[i]);

  cout << count;
}