#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double EPS = 1e-6;
int main() {
	ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
	char line[256];
	double lg2 = log10(2), A, v;
	int B;
	while(cin >> line && strcmp(line, "0e0") != 0) {
		*strchr(line, 'e') = ' '; // 找到第一个e将它替换成空格
		sscanf(line, "%lf%d", &A, &B);
		v = log10(A) + B;
		for(int M = 1; M <= 10; M++) {
			int E = round(log10((v + M * lg2 - log10(pow(2, M) - 1)) / lg2 + 1) / lg2);
				if(fabs(((1 << E) - 1) * lg2 + log10(pow(2, M) - 1) - M * lg2 - v) <= EPS) {
					cout << M - 1 << " " << E << endl;
					break;
				}
		}
	}
	
	return 0;
}

