#include <iostream>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, a[100001] = {}, x;
  bool fact[2000001];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> x;

  int answer = 0;
  for (int i = 0; i < n; i++) {
    if (x - a[i] > 0 && fact[x-a[i]]) answer++;
    fact[a[i]] = true;
  }

  cout << answer;
}