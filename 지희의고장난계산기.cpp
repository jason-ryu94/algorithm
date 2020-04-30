#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
int memo[10];
int d[1000001];
int m[1000001];


int go(int x, int y) {
	if (d[x] != -1 && d[y] != -1) {
		return d[x] + d[y] + 1;
	}
	int t1 = -1;
	int t2 = -1;
	if (d[x] == -1) {
		for (int i = 2; i < x; i++) {
			if (x % i == 0) {
				int nx, ny;
				nx = i;
				ny = x / i;
				int temp = go(nx, ny);
				if (t1 == -1 || t1 > temp) t1 = temp;
				if (t1 != -1) d[x] = t1;
			}
		}
	}
	if (d[y] == -1) {
		for (int i = 2; i < x; i++) {
			if (y % i == 0) {
				int nx, ny;
				nx = i;
				ny = y / i;
				int temp = go(nx, ny);
				if (t2 == -1 || t2 > temp) t2 = temp;
				if (t2 != -1) d[y] = t2;
			}
		}
	}
	if (t1 != -1 && t2 != -1) {
		if (d[x * y] == -1) {
			d[x * y] = t1 + t2 + 1;
		}
		else {
			d[x * y] = min(d[x * y], t1 + t2 + 1);
		}		
	}

	return d[x * y];
}



int main() {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		for (int i = 0; i < 10; i++) {
			cin >> memo[i];
		}
		int n;
		cin >> n;
		if (n == 1) {
			if (memo[n] == 1) {
				cout << '#' << t << ' ' << 2 << '\n';
			}
			else {
				cout << '#' << t << ' ' << -1 << '\n';
			}
			continue;
		}
		memset(d, -1, sizeof(d));
		for (int i = n; i > 1; i--) {
			if (n % i != 0) continue;
			string s;
			s = to_string(i);
			int num = s.length();
			bool ok = true;
			for (int j = 0; j < num; j++) {
				if (memo[s[j] - '0'] == 0) {
					ok = false;
					break;
				}
			}
			if (ok) d[i] = num;
		}

		int ans = d[n];
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				int temp = go(i, n / i);
				if (temp != -1 && (ans == -1 || ans > temp)) {
					
					ans = temp;
				}
			}
		}
		if (ans == -1) ans = -2;
		cout << '#' << t <<' ' << ans +1 << '\n';
	}
	return 0;
}
// 각 곱하기 에서 두 수로 나눠서 다이나믹 진행
