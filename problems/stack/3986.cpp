#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  int T;
  cin >> T;

  int answer = 0;

  while(T--){
    string str;
    cin >> str;

    stack<char> st;

    for (auto c : str) {
      if (!st.empty()) {
        if (st.top() == c) st.pop();
        else st.push(c);
      }else st.push(c);
    }

    if (st.empty()) answer++;
  }
  
  cout << answer;
}