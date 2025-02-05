#include <iostream>
#include <string>
using namespace std;

int lft, chance; // 还要猜lft个位置,错chance次后会输
bool win, lose; // win=1表示赢了, lose=1表示输了
string s, s2;

void guees(char ch) {
	int bad = 1;
	int len = s.length();
	for(int i = 0; i < len; i++) {
		if(s[i] == ch) {
			lft--;
			s[i] = ' ';
			bad = 0;
		}
		
	}
	if(bad) --chance;
	if(!chance) lose = 1;
	if(!lft) win = 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	int rnd;
	while(cin >> rnd >> s >> s2 && rnd != -1) {
		cout << "Round " << rnd << endl;
		win = lose = 0; // init
		lft = s.length();
		chance = 7;
		int len = s2.length();
		for(int i = 0; i < len; i++) {
			guees(s2[i]); // 猜一个字母
			if(win || lose) break; // 检查状态
		}
		if(win) cout << "You win.\n";
		else if(lose) cout << "You lose.\n";
		else cout << "You chickened out.\n";
	}
	
	return 0;
}
