#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int number;
  cin >> number;
  int arr[9];
  for (int i = 0; i < 9; i++) arr[i] = 0;

  while (number) {
    int x = number % 10;
    if (x == 9) x = 6;
    arr[x]++;
    number /= 10;
  }

  int result = 0;
  for (int i = 0; i < 9; i++) {
    if (i == 6) arr[i] = (arr[i] % 2 == 1) ? (arr[i] / 2) + 1 : arr[i] / 2;

    if (result < arr[i]) result = arr[i];
  }

  cout << result;
}