#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string s;
const char sam[9] = "SAMSUNG";
long long d[8];

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int ans = 0;
		cin >> s;
		memset(d, 0, sizeof(d));
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'S') {
				d[0] += 1;
				d[3] += d[2];
				d[0] %= 1000000007;
				d[3] %= 1000000007;
			}
			else if (s[i] == 'A') {
				d[1] += d[0];
				d[1] %= 1000000007;
			}
			else if (s[i] == 'M') {
				d[2] += d[1];
				d[2] %= 1000000007;
			}
			else if (s[i] == 'U') {
				d[4] += d[3];
				d[4] %= 1000000007;
			}
			else if (s[i] == 'N') {
				d[5] += d[4];
				d[5] %= 1000000007;
			}
			else if (s[i] == 'G') {
				d[6] += d[5];
				d[6] %= 1000000007;
			}
		}


		cout << '#' << t << ' ' << d[6] << '\n';
	}
}
