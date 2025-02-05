#include <iostream>
#include <string>
using namespace std;

const int N = 1e5 + 10;
int n, m;
struct Node {
	string job;
	bool inward; 
} toys[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> toys[i].inward >> toys[i].job;
	}
	
	int p = 0; 
	for (int i = 0; i < m; i++) {
		int d, steps;
		cin >> d >> steps;
		int mp = toys[p].inward ? -1 : 1; 
		if (d == 0) { 
			mp *= -1; 
		}
		p = (p + mp * steps + n) % n; 
	}
	cout << toys[p].job << endl;
	
	return 0;
}
