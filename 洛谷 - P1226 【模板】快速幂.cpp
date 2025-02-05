#include <iostream>
using namespace std;
long long qmi(long long m, long long k, long long p)
{
	long long res = 1 % p, t = m;
	while (k)
	{
		if (k&1) res = res * t % p;
		t = t * t % p;
		k >>= 1;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0), cout.tie(0);
	long long m ,k, p;
	cin >> m >> k >> p;
	cout << m << '^' << k << " mod " << p << "=";
	cout << qmi(m, k, p);
	
	return 0;
}

