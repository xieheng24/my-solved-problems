#include <iostream>
#include <cstring>
using namespace std;

const int N = 25 * 2501 + 15;
char s[N];
int cnt;
int cntw, cntl;
int cntc;
void fen(int n) {
	int cntw = 0, cntl = 0; 
	for (int i = 0; i < cnt; i++) {
		if ((cntw >= n || cntl >= n) && abs(cntw - cntl) >= 2) {
			cout << cntw << ":" << cntl << endl;
			cntw = cntl = 0;
		}
		if (s[i] == 'W') cntw++;
		else if (s[i] == 'L') cntl++;
		
	}
	if (cntw > 0 || cntl > 0) {
		cout << cntw << ":" << cntl << endl;
	}
	if ((cntw >= n || cntl >= n) && cntw != cntl) {
		cout << 0 << ":" << 0 << endl;
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	char ch;
	while(cin >> ch && ch != 'E') {
		if(ch == 'W' || ch == 'L') s[cnt++] = ch;
	}
	if(ch == 'E' && cnt == 0) {
		cout << "0:0\n\n0:0";
	}
	fen(11);
	cout << endl;
	fen(21);
	
	return 0;
}
