#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int a[9][9];
vector<int> order[3];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 20; i++) {
		int x;
		cin >> x;
		order[1].push_back(x-1);
	}
	for (int i = 0; i < 20; i++) {
		int x;
		cin >> x;
		order[2].push_back(x-1);
	}
	bool ans = false;
	for (int i = 0; i < n; i++) {
		order[0].push_back(i);
	}
	sort(order[0].begin(), order[0].end());
	do {
		bool ok = true;
		int p1 = 0;
		int p2 = 1;
		int index[3] = { 0, 0, 0 };
		int victory[3] = { 0, 0, 0 };
		while (ok) {
			if (index[0] >= n) break;
			int p1_ = order[p1][index[p1]];
			int p2_ = order[p2][index[p2]];
			index[p1]++;
			index[p2]++;
			if (a[p1_][p2_] == 2) {
				victory[p1]++;
				if (victory[p1] == k) ok = false;
				p2 = 3 - (p1 + p2);
			}
			else if (a[p1_][p2_] == 1) {
				if (p1 > p2) {
					victory[p1]++;
					if (victory[p1] == k) ok = false;
					p2 = 3 - (p1 + p2);
				}
				else if (p2 > p1) {
					victory[p2]++;
					if (victory[p2] == k) ok = false;
					p1 = 3 - (p1 + p2);
				}
			}
			else if (a[p1_][p2_] == 0) {
				victory[p2]++;
				if (victory[p2] == k) ok = false;
				p1 = 3 - (p1 + p2);
			}
		}
		if (victory[0] == k) {
			ans = true;
			break;
		}


	} while (next_permutation(order[0].begin(), order[0].end()));
	if (ans) cout << 1;
	else cout << 0;
}
