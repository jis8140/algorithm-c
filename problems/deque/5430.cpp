#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;

void parse(string& tmp, deque<int>& dq) {
  int cur = 0;
  for (int i = 1; i + 1 < tmp.size(); i++) {
    if (tmp[i] == ',') {
      dq.push_back(cur);
      cur = 0;
    } else {
      cur = 10 * cur + (tmp[i] -'0');
    }
  }

  if (cur != 0) dq.push_back(cur);
}

void print(deque<int>& dq) {
  cout << "[";
  for (int i = 0; i < dq.size(); i++) {
    cout << dq[i];
    if (i + 1 != dq.size()) cout << ",";
  }
  cout << "]\n";
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    deque<int> dq;
    string command;
    cin >> command;
    int N;
    cin >> N;
    bool isError = false;
    int rev = 0;
    string number;
    cin >> number;
    parse(number, dq);

    for (auto c: command) {
      if (c == 'R') rev = 1 - rev;
      else {
        if (dq.empty()) isError = true;
        else {
          if (!rev) dq.pop_front();
          else dq.pop_back();
        }
      }
    }

    if (isError) cout << "error\n";
    else {
      if(rev) reverse(dq.begin(), dq.end());
      print(dq);
    }
  }
}