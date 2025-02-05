#include <iostream>
#include <vector>
using namespace std;

bool check(long long k, long long m) {
	long long n = 2 * k; 
	long long pos = 0;
	vector<bool> alive(n, true); 
	for (long long i = 0; i < k; i++) {
		long long count = 0;
		while (count < m) {
			if (alive[pos]) {
				count++;
			}
			pos = (pos + 1) % n;
		}
		pos = (pos - 1 + n) % n;
		if (pos < k) {
			return false;
		}
		alive[pos] = false;
	}
	return true;
}

int main() {
	long long k;
	cin >> k;
	
	for (long long m = 1; ; m++) {
		if (check(k, m)) {
			cout << m << endl;
			break;
		}
	}
	return 0;
}
