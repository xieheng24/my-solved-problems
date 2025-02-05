#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> result(n, 0);
	int pos = 0; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			pos = (pos + 1) % n;
			while (result[pos] != 0) {
				pos = (pos + 1) % n;
			}
		}
		result[pos] = i;
		while (result[pos] != 0) {
			pos = (pos + 1) % n;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	
	return 0;
}
