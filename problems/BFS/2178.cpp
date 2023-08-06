#include <iostream>
#include <queue>
#include <string>
#include <utility>

#define x first
#define y second

using namespace std;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;

  string str;
  int board[101][101];
  int score[101][101];
  
  for (int i = 0; i < n; i++) fill(score[i], score[i]+m, -1);

  for (int i = 0; i < n; i++) {
    cin >> str;

    int j = 0;
    for (auto c: str) {
      board[i][j++] = c - '0';
    }
  }

  queue<pair<int,int>> Q;
  Q.push({0, 0});
  score[0][0] = 1;

  while (!Q.empty()) {
    pair<int, int> cur = Q.front(); Q.pop();

    for (int i = 0; i < 4; i++) {
      int cur_x = cur.x + dx[i];
      int cur_y = cur.y + dy[i];

      if (cur_x < 0 || cur_y < 0 || cur_x >= n || cur_y >= m) continue;

      if (score[cur_x][cur_y] < 0 && board[cur_x][cur_y] == 1) {
        Q.push({cur_x, cur_y});
        score[cur_x][cur_y] = score[cur.x][cur.y] + 1;
      }
    }
  }

  cout << score[n-1][m-1];
}