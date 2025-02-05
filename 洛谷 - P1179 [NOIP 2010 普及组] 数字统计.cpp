#include <iostream>
using namespace std;

int cnt;
int l, r;
int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	cin >> l >> r;
	for(int i = l; i <= r; i++) {
		int sum = i;
		while(sum > 0) {
			int tmp = sum % 10;
			if(tmp == 2) cnt++;
			sum /= 10;
		}
	}
	cout << cnt;
	
	return 0;
}
