#include <iostream>
using namespace std;

int biao[5][5] =        //游戏的结果情况，1表示A赢，-1表示A输，0表示平
{
	{0, -1, 1, 1, -1},
	{1, 0, -1, 1, -1},
	{-1, 1, 0, -1, 1},
	{-1, -1, 1, 0, 1},
	{1, 1, -1, -1, 0}
};
int ga[210], gb[210];
int n, na, nb, cnta, cntb, fa, fb;

int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> na >> nb;
	for(int i = 0; i < na; i++) {
		cin >> ga[i];
	}
	for(int i = 0; i < nb; i++) {
		cin >> gb[i];
	}
	for(int i = 0; i < n; i++) {
		int tmp = biao[ga[i % na]][gb[i % nb]];
		if(tmp == 1) fa++;
		if(tmp == -1) fb++;
	}
	cout << fa << " " << fb;
	
	return 0;
}
