#include <iostream>
#include <iomanip>
using namespace std;

const int N = 25;
int n, k, m, a[N];
int go(int p, int d, int t) {
	while(t--) {
		do {
			p = (p + d + n - 1) % n + 1;
		}
		while(a[p] == 0); // 走到下一个非零数字
	}
	return p;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	while(cin >> n >> k >> m && n) {
		for(int i = 1; i <= n; i++) {
			a[i] = i;
		}
		int lft = n; // 还剩下的人数
		int p1 = n, p2 = 1;
		while(lft) {
			p1 = go(p1, 1, k);
			p2 = go(p2, -1, m);
			cout << fixed << setw(3) << p1;
			lft--;
			if(p2 != p1) {
				cout << fixed << setw(3) << p2;
				lft--;
			}
			a[p1] = a[p2] = 0;
			if(lft) cout << ",";
		}
		cout << endl;
	}
	
	return 0;
}
