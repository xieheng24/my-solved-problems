#include <bits/stdc++.h>
using namespace std;

int n, qx, qy, tx, ty, kx, ky;
const int MAXN = 1e3 + 10;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int ans[MAXN][MAXN];

bool bfs(int x, int y) {
	queue<pair<int, int>> q;
	ans[x][y] = -1;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		if (p.first == tx && p.second == ty) return true; 
		for (int i = 0; i < 8; i++) {
			int x1 = p.first + dx[i];
			int y1 = p.second + dy[i];
			if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && ans[x1][y1] == 0) {
				ans[x1][y1] = -1;
				q.push(make_pair(x1, y1));
			}
		}
	}
	return false;
}

void init() {
	for (int i = 0; i < n; i++) {
		ans[qx][i] = -1; 
		ans[i][qy] = -1; 
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i - j == qx - qy || i + j == qx + qy) { 
				ans[i][j] = -1;
			}
		}
	}
	ans[qx][qy] = -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(ans, 0, sizeof(ans));
		cin >> n >> qx >> qy >> kx >> ky >> tx >> ty;
		// 将坐标从1-based转换为0-based
		qx--; qy--; kx--; ky--; tx--; ty--;
		init();
		if (ans[kx][ky] == -1 || ans[tx][ty] == -1) {
			cout << "NO\n";
			continue;
		}
		bool b = bfs(kx, ky);
		if (b) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
