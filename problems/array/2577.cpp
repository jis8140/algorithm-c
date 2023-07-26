#include <iostream>
#include <string>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  int arr[10];
  for (int i = 0; i < 10; i++) arr[i] = 0;
  long long result = a * b * c;
  string str = to_string(result);

  for (auto s : str)arr[s - '0'] += 1;
  for (int i = 0; i < 10; i++) cout << arr[i] << "\n";
}