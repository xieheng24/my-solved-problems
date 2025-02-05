#include <iostream>
#include <queue>
using namespace std;

int n, m;
int s[15][15];
bool vis[15][15][7]; 
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct State {
	int x, y; 
	int hp;   
	int cnt;  
};

int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	int hx = 0, hy = 0; 
	int a = 0, b = 0;   
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
			if (s[i][j] == 3) hx = i, hy = j;
			if (s[i][j] == 2) a = i, b = j;  
		}
	}
	
	queue<State> q;
	q.push({a, b, 6, 0}); 
	vis[a][b][6] = true;  
	
	while (!q.empty()) {
		State cur = q.front();
		q.pop();
		if (cur.x == hx && cur.y == hy) {
			cout << cur.cnt << endl;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int xx = cur.x + dx[i];
			int yy = cur.y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && s[xx][yy] != 0) {
				int new_hp = cur.hp - 1;
				if (new_hp <= 0) continue; 
				if (s[xx][yy] == 4) new_hp = 6;
				
				if (!vis[xx][yy][new_hp]) {
					vis[xx][yy][new_hp] = true;
					q.push({xx, yy, new_hp, cur.cnt + 1});
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
