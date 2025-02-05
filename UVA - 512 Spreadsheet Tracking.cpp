#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#define maxd 100 //不固定最大值不是很好处理交换的操作
using namespace std;

struct node {
	int c = 0, r = 0; //记录原来的位置和新的位置
};
//每次操作之前把d2=d,然后根据操作的行数把d2的值赋给d,比如删除第1行，就把d2的第2行copy给d的第1行
void copy(char t, int p, int q, int c, vector<vector<node >> &d, vector<vector<node >> &d2) {
	if (t == 'R') { //复制到行
		for (int i = 1; i <= c; i++) {
			d[p][i].r = d2[q][i].r;
			d[p][i].c = d2[q][i].c;
		}
	} else { //复制到列
		for (int i = 1; i <= c; i++) {
			d[i][p].r = d2[i][q].r;
			d[i][p].c = d2[i][q].c;
		}             //复制列到列
	}
}
void dr(int c, int &r, vector<int> cols, vector<vector<node >> &d, vector<vector<node >> &d2) {
	int cnt2 = 0;

	for (int i = 1; i <= r; ++i) {
		if (!cols[i])
			copy('R', ++cnt2, i, c, d, d2); //遇到1时，cnt2少加一次，i正常递增
	}

	r = cnt2;
}
void dc(int &c, int r, vector<int> cols, vector<vector<node >> &d, vector<vector<node >> &d2) {
	int cnt2 = 0;

	for (int i = 1; i <= c; ++i) {
		if (!cols[i])
			copy('C', ++cnt2, i, r, d, d2);
	}

	c = cnt2;
}
void ir(int c, int &r, vector<int> cols, vector<vector<node >> &d, vector<vector<node >> &d2) {
	int cnt2 = 0;

	for (int i = 1; i <= r; ++i) {
		if (cols[i])
			copy('R', ++cnt2, 0, c, d, d2); //遇到1时，cnt2 多加一次

		copy('R', ++cnt2, i, c, d, d2);
	}

	r = cnt2; //新的行数
}
void ic(int &c, int r, vector<int> cols, vector<vector<node >> &d, vector<vector<node >> &d2) {
	int cnt2 = 0;

	for (int i = 1; i <= c; ++i) {
		if (cols[i])
			copy('C', ++cnt2, 0, r, d, d2); //遇到1时，cnt2 多加一次

		copy('C', ++cnt2, i, r, d, d2);
	}

	c = cnt2; //新的行数
}
int main() {
	// ofstream cout("512output.txt");
	// ifstream cin("512input.txt");
	int r, c, sheet_n = 0, o_n; //n sheets,n operations

	while (cin >> r >> c >> o_n && r) {
		vector<vector<node >> d(maxd), d2(maxd), ans(maxd);

		for (int i = 0; i < maxd; ++i) { //注意i=0
			d[i].resize(maxd);
			d2[i].resize(maxd);
			ans[i].resize(maxd);
		}

		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				d[i][j].c = j;
				d[i][j].r = i;
			}
		}

		map<string, int> msi;
		msi["DR"] = 1;
		msi["DC"] = 2;
		msi["IC"] = 3;
		msi["IR"] = 4;
		string op;

		for (int i = 0; i < o_n; ++i) {
			cin >> op;

			if (op[0] == 'E') {
				int c1, r1, c2, r2;
				cin >> r1 >> c1 >> r2 >> c2;
				swap(d[r1][c1].c, d[r2][c2].c);
				swap(d[r1][c1].r, d[r2][c2].r);
			} else {
				vector<int> cols(maxd);
				int op_n, k; //for each op there is n op,row k or column k
				cin >> op_n;

				for (int j = 0; j < op_n; ++j) {
					cin >> k;
					cols[k] = 1;
				}

				d2 = d;

				switch (msi[op]) {
					case 1: { //DR
						// cout<<r<<" "<<c<<endl;
						dr(c, r, cols, d, d2);
						break;
					}

					case 2: { //DC
						dc(c, r, cols, d, d2);
						break;
					}

					case 3: { //IC
						ic(c, r, cols, d, d2);
						break;
					}

					case 4: { //IR
						ir(c, r, cols, d, d2);
						break;
					}
				}
			}
		}
		/*
		ans存储经过增减调换后的数组，ans的内容为变化后的数组d的坐标
		比如d[1][1]的值处理后是3,2，那么ans[3][2]的值就是1,1
		*/
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				//d[i][j].r可能为0，所以最上面初始化的时候i要从0开始resize
				ans[d[i][j].r][d[i][j].c].r = i;
				ans[d[i][j].r][d[i][j].c].c = j;
			}
		}

		if (sheet_n)
			cout << endl;

		cout << "Spreadsheet #" << ++sheet_n << endl;
		int q_n, q_r, q_c;
		cin >> q_n;

		for (int i = 0; i < q_n; ++i) {
			cin >> q_r >> q_c;
			cout << "Cell data in (" << q_r << "," << q_c << ") ";

			if (ans[q_r][q_c].c == 0)
				cout << "GONE" << endl;
			else
				cout << "moved to (" << ans[q_r][q_c].r << "," << ans[q_r][q_c].c << ")" << endl;
		}
	}

	return 0;
}
