#include <iostream>

using namespace std;
using ll = long long;

ll func(ll n, ll r, ll c) {
  if (n == 0) return 0;
  ll k = 1 << (n - 1);

  if (r < k && c < k) return func(n-1, r, c);
  else if (r < k && c >= k) return k*k + func(n-1, r, c - k);
  else if (r >= k && c < k) return 2*k*k + func(n-1, r - k, c);
  else return 3*k*k + func(n-1, r - k, c - k);
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  int N;
  ll r, c;
  cin >> N >> r >> c;
  cout << func(N, r, c);
}