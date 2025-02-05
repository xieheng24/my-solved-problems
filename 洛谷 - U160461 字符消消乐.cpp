#include <iostream>
#include <stack>
#include <cstring> 
using namespace std;

const int N = 1e7 + 10; 
char res[N];

void re(const char* s) {
	stack<char> stk;
	memset(res, 0, N); 
	int res_index = 0; 
	while (*s) { 
		char c = *s++;
		if (!stk.empty()) {
			char top = stk.top();
			if ((c >= 'a' && c <= 'z' && top == c - 'a' + 'A') ||
				(c >= 'A' && c <= 'Z' && top == c - 'A' + 'a')) {
				stk.pop();
				continue;
			}
		}
		stk.push(c);
	}
	
	while (!stk.empty()) {
		res[res_index++] = stk.top();
		stk.pop();
	}
	for (int i = 0; i < res_index / 2; ++i) {
		char temp = res[i];
		res[i] = res[res_index - i - 1];
		res[res_index - i - 1] = temp;
	}
	res[res_index] = '\0';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	char input[N];
	cin >> input; 
	
	re(input);
	cout << res;
	
	return 0;
}
