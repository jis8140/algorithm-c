#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define x first
#define y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> m >> n;

  int tomato[1001][1001];
  int dist[1001][1001];
  queue <pair<int, int>> Q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> tomato[i][j];
      if (tomato[i][j] == 1) Q.push({i, j});
      if (tomato[i][j] == 0) dist[i][j] = -1;
    }
  }


  while (!Q.empty()) {
    pair <int, int> cur = Q.front(); Q.pop();

    for (int i = 0; i < 4; i++) {
      int cur_x = cur.x + dx[i];
      int cur_y = cur.y + dy[i];

      if (cur_x < 0 || cur_y < 0 || cur_x >= n || cur_y >= m) continue;
      if (dist[cur_x][cur_y] >= 0) continue;
      dist[cur_x][cur_y] = dist[cur.x][cur.y] + 1;
      Q.push({cur_x, cur_y});
    }
  }

  int mx = 0;
  bool isComplete = true;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j] == -1) {
        isComplete = false;
        break;
      }
      mx = max(mx, dist[i][j]);
    }
  }

  if (isComplete) cout << mx;
  else cout << -1;
}