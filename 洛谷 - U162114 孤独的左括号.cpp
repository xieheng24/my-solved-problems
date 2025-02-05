#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e7 + 10;
char s[N];
int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	cin >> s;
	int u = 0;
	int l = 0; 
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		char c = s[i];
		if (c == '(') {
			l += u;
			u++;
		} else if (c == ')') {
			u--;
		}
	}
	cout << l << endl;
	
	return 0;
}
