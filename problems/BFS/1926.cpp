#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

#define X first
#define Y second

using namespace std;


int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int board[501][501];
bool visited[501][501];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> board[i][j];
  }

  int mx = 0, num = 0;
  queue <pair<int,int>> Q;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++) {
      if (visited[i][j] || board[i][j] == 0) continue;
      
      num++;
      Q.push({i,j});
      visited[i][j] = true;

      int area = 0;
      while (!Q.empty()) {
        area++;
        pair<int, int> cur = Q.front(); Q.pop();
        for (int p = 0; p < 4; p++){
          int cur_x = cur.X + dx[p];
          int cur_y = cur.Y + dy[p];


          if (cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= m) continue;

          if (!visited[cur_x][cur_y] && board[cur_x][cur_y] == 1) {
            Q.push({cur_x, cur_y});
            visited[cur_x][cur_y] = true;
          }
        }
      }

      mx = max(mx, area);
    }
  }

  cout << num << "\n" << mx;
}