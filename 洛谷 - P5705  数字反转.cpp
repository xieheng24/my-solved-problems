#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	cin >> s;
	reverse(s.begin(), s.end());
	cout << s << endl;
	
	return 0;
}
