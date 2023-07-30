#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  int count = 1;
  stack <int> st;
  vector <char> v;
  bool fact = true;
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;

    if (temp >= count){
      while (temp >= count) {
        st.push(count++);
        v.push_back('+');
      }
      st.pop();
      v.push_back('-');
    } else {
      if (st.empty() || temp != st.top()) {
        fact = false;
        break;
      }
      else {
        st.pop();
        v.push_back('-');
      }
    }
  }

  if (fact){
    for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
  } else cout << "NO";
}