#include <cstdio>
#include <cstring>
using namespace std;

int readchar() {
	while(1) {
		int ch = getchar();
		if(ch != '\n' && ch != '\r') return ch; // 一直读到非换行符为止
	}
}
int readint(int c) {
	int v = 0;
	while(c--) {
		v = v * 2 + readchar() - '0';
	}
	return v;
}
int code[8][1 << 8];
int readcodes() {
	memset(code, 0, sizeof code);
	code[1][0] = readchar(); // 直接调到下一行开始读取,如果输入已结束,会读到EOF
	for(int len = 2; len <= 7; len++) {
		for(int i = 0; i < (1 << len) - 1; i++) {
			int ch = getchar();
			if(ch == EOF) return 0;
			if(ch == '\n' || ch == '\r') return 1;
			code[len][i] = ch;
		}
	}
	return 1;
}
int main() {
	while(readcodes()) {
		while(1) {
			int len = readint(3);
			if(len == 0) break;
			for(;;) {
				int v = readint(len);
				if(v == (1 << len) - 1) break;
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
	return 0;
}
