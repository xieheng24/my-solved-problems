#include <cctype>
#include <iostream>
using namespace std;

char ch;
int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	cin >> ch;
	cout << (char)toupper(ch) << endl;
	
	return 0;
}
