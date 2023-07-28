#include <iostream>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int man[7] = {}, woman[7] = {};
  int N, K;
  int a, b;

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    if (a==0) woman[b]++; 
    else man[b]++;
  }

  int count = 0;
  for (int i = 1; i < 7; i++){
    if (woman[i] % K != 0) count += (woman[i] / K) + 1;
    else count += (woman[i] / K);
    
    if (man[i] % K != 0) count += (man[i] / K) + 1;
    else count += (man[i] / K);
  }
  cout << count;
}