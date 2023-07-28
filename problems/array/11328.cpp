#include <iostream>
#include <string>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  string a, b;
  int alphabet[27] = {};

  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> a >> b;

    for (auto s : a) alphabet[s-'a']++;
    for (auto s : b) alphabet[s-'a']--;

    bool fact = true;
    for (int i = 0; i < 27; i++) {
      if (alphabet[i] != 0) {
        fact = false;
        alphabet[i] = 0;
      }
    }

    if (fact) cout << "Possible\n";
    else cout << "Impossible\n";
  }
}