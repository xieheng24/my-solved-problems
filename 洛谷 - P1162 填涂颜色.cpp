#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 35; 
int ans[maxn][maxn]; 
bool vis[maxn][maxn];

const int dx[] = {0, 0, 1, -1}; 
const int dy[] = {-1, 1, 0, 0};

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = true; 
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && ans[nx][ny] == 0 && !vis[nx][ny]) {
				vis[nx][ny] = true; 
				q.push({nx, ny});
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ans[i][j];
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		if (ans[i][0] == 0 && !vis[i][0]) bfs(i, 0); 
		if (ans[i][n - 1] == 0 && !vis[i][n - 1]) bfs(i, n - 1); 
	}
	for (int j = 0; j < n; j++) {
		if (ans[0][j] == 0 && !vis[0][j]) bfs(0, j); 
		if (ans[n - 1][j] == 0 && !vis[n - 1][j]) bfs(n - 1, j); 
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[i][j] == 0 && !vis[i][j]) {
				ans[i][j] = 2;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
