#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool ismatch(char left, char right) {
	if (left == '(' && right == ')') return true;
	if (left == '[' && right == ']') return true;
	if (left == '{' && right == '}') return true;
	return false;
}

bool check(const string& s) {
	stack<char> stk;
	for (char ch : s) {
		if (ch == '(' || ch == '[' || ch == '{') {
			stk.push(ch);
		} else if (ch == ')' || ch == ']' || ch == '}') {
			if (stk.empty() || !ismatch(stk.top(), ch)) {
				return false;
			}
			stk.pop();
		} else if (ch == '@') {
			break; 
		}
	}
	return stk.empty(); 
}

int main() {
	string s;
	cin >> s;
	if (check(s)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}
