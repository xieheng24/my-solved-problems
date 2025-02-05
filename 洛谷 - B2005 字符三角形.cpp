#include <iostream>
using namespace std;

char ch;
int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	cin >> ch;
	cout << "  ";
	cout << ch;
	cout << "  " << endl;
	cout << " ";
	for(int i = 0; i < 3; i++) cout << ch;
	cout << " " << endl;
	for(int i = 0; i < 5; i++) cout << ch;
	cout << endl;
	
	return 0;
}
