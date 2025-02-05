#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	string a, b;
	while (cin >> a >> b) {
		vector<int> cnt1(26, 0), cnt2(26, 0); 
		for (char ch : a) {
			if (ch >= 'A' && ch <= 'Z') { 
				cnt1[ch - 'A']++;
			}
		}
		for (char ch : b) {
			if (ch >= 'A' && ch <= 'Z') { 
				cnt2[ch - 'A']++;
			}
		}
		sort(cnt1.begin(), cnt1.end());
		sort(cnt2.begin(), cnt2.end());
		bool flag = true;
		for (int i = 0; i < 26; i++) {
			if (cnt1[i] != cnt2[i]) {
				flag = false;
				break;
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
