#include <iostream>

using namespace std;

void hanoi(int a, int b, int c) {
  if (c == 0) return;

  hanoi(a, 6-a-b, c-1);
  cout << a << " " << b << "\n";
  hanoi(6-a-b, b, c-1);
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int N;
  cin >> N;

  cout << (1 << N) - 1 << "\n";
  hanoi(1, 3, N);
}