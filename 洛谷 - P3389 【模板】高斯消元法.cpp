#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

const int N = 1e2 + 15;
const double eps = 1e-6;
double a[N][N];
int n;

int gauss() {
	int c, r;
	for (c = 0, r = 0; c < n; c++) {
		int t = r;
		for (int i = r; i < n; i++) {
			if (fabs(a[i][c]) > fabs(a[t][c])) t = i;
		}
		if (fabs(a[t][c]) < eps) continue;
		for (int i = c; i <= n; i++) {
			swap(a[t][i], a[r][i]);
		}
		for (int i = n; i >= c; i--) {
			a[r][i] /= a[r][c];
		}
		for (int i = r + 1; i < n; i++) {
			if (fabs(a[i][c]) > eps) {
				for (int j = n; j >= c; j--) {
					a[i][j] -= a[r][j] * a[i][c];
				}
			}
		}
		r++;
	}
	if (r < n) {
		for (int i = r; i < n; i++) {
			if (fabs(a[i][n]) > eps) return 2; // 无解
		}
		return 1; // 无数解
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			a[i][n] -= a[i][j] * a[j][n];
		}
	}
	return 0; // 唯一解
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			cin >> a[i][j];
		}
	}
	int t = gauss();
	if (t == 1) cout << "No Solution";
	else if (t == 2) cout << "No Solution";
	else {
		for (int i = 0; i < n; i++) cout << fixed << setprecision(2) << a[i][n] << endl;
	}
	
	return 0;
}
