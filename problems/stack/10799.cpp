#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  string str;
  cin >> str;
  stack <char> st;

  int answer = 0;
  int isRazer = 0;

  for (auto c : str) {
    if (c == '(') {
      if (!isRazer) isRazer =  1 - isRazer;
      st.push(c);
    } else {
      if (isRazer) {
        isRazer =  1 - isRazer;
        st.pop();
        answer += st.size();
      } else {
        st.pop();
        answer += 1;
      }
    }
  }

  cout << answer;
}