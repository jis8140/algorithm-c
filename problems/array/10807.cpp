#include <iostream>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, a[101] = {}, v;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  cin >> v;

  int count = 0;
  for (int i = 0; i < N; i++){
    if (a[i] == v) count++;
  }

  cout << count;
}