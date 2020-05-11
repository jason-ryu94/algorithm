#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <map>
#include <array>
#include <stack>

using namespace std;
long long s, t;
queue<pair<long long, string>> q;


int main() {
	cin >> s >> t;
	q.push(make_pair(s, ""));
	
	if (s == t) {
		cout << 0;
		return 0;
	}
	string ans = "";
	int k = -1;
	while (!q.empty()) {
		string st;
		long long x;
		tie(x, st) = q.front();
		q.pop();
		long long nx;
		string nst;
		if (x * x <= t && x != 1) {
			nx = x * x;
			nst = st + '*';
			q.push(make_pair(nx, nst));
			if (nx == t) {
				ans = nst;
				break;
			}
		}
		if (x * 2 <= t) {
			nx = x * 2;
			nst = st + '+';
			q.push(make_pair(nx, nst));
			if (nx == t) {
				ans = nst;
				break;
			}
		}
		
		if (k == -1) {
			q.push(make_pair(1, "/"));
			k = 0;
			if (t == 1) {
				ans = "/";
				break;
			}
		}
	}
	if (ans == "") {
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}
