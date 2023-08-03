#include<iostream>
#include<stack>
#include<string>
#include<utility>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  string str;
  cin >> str;

  stack <pair<char, int>> st;
  stack <pair<int, int>> temp;

  int count = 0;
  bool isValid = true;
  for (auto c : str) {
    if (c == '(' || c == '[') st.push({c, count++});
    else {
      if (c == ')') {
        if (st.empty() || st.top().first != '(') {
          isValid = false;
          break;
        }

        if (count == st.top().second + 1) {
          temp.push({2, count++});
          st.pop();
        } else {
          int tempValue = 0;
          while (!temp.empty() && temp.top().second > st.top().second) {
            tempValue += temp.top().first;
            temp.pop();
          }
          temp.push({2 * tempValue, st.top().second});
          count++;
          st.pop();
        }
      }
      else {
        if (st.empty() || st.top().first != '[')  {
          isValid = false;
          break;
        }

        if (count == st.top().second + 1) {
          temp.push({3, count++});
          st.pop();
        } else {
          int tempValue = 0;
          while (!temp.empty() && temp.top().second > st.top().second) {
            tempValue += temp.top().first;
            temp.pop();
          }
          temp.push({3 * tempValue, st.top().second});
          count++;
          st.pop();
        }
      } 
    }
  }

  int answer = 0;
  if (!isValid) cout << answer;
  else {
    while (!temp.empty()) {
      answer += temp.top().first;
      temp.pop();
    }
    cout << answer;
  }
}