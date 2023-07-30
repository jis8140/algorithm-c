#include <iostream>
#include <stack>

using namespace std;

// stack을 이용한 풀이 방법..

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  long long result = 0;
  stack<long long> st;
  while (N--){
    long long a;
    cin >> a;
    
    if (a == 0){
      long long value = st.top();
      st.pop();
      result -= value;
    }
    else {
      st.push(a);
      result += a;
    }
  }

  cout << result;
}