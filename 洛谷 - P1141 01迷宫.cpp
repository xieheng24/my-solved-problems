#include <bits/stdc++.h>
using namespace std;

int n, m;
const int maxn = 1005;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int grid[maxn][maxn]; 
int vis[maxn][maxn];  
int cnt[maxn * maxn]; 
int block_id = 0;    

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	vis[x][y] = block_id;
	cnt[block_id] = 1;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && grid[nx][ny] != grid[p.first][p.second]) {
				vis[nx][ny] = block_id;
				cnt[block_id]++;
				q.push({nx, ny});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			grid[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				block_id++;
				bfs(i, j);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--; 
		cout << cnt[vis[x][y]] << endl;
	}
	
	return 0;
}
