#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  stack <long long> st;
  stack <pair<long long, int>> box;
  int result[500001] = {};
  int count = N;
  long long a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    st.push(a);
  }

  while (!st.empty()) {
    if (box.empty()) {
      long long value = st.top();
      box.push({value, st.size()});
      st.pop();
      count--;
      continue;
    }

    if (st.top() >= box.top().first) {
      while (!box.empty() && st.top() >= box.top().first){
        result[box.top().second - 1] = st.size();
        box.pop();
      }
    } else {
      long long value = st.top();
      box.push({value, st.size()});
      st.pop();
    }
  }

  for (int i = 0; i < N; i++) cout << result[i] << " ";
}