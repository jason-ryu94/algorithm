#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int p[8];
int w[8];

int dfs(int index, int num) {
	if (index == n) return num;
	int ans = 0;
	bool ok = false;
	if (p[index] <= 0) {
		int temp = dfs(index + 1, num);
		if (temp > ans) ans = temp;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i == index) continue;
			if (p[i] <= 0) continue;
			int nnum = num;
			p[index] -= w[i];
			if (p[index] <= 0) nnum += 1;
			p[i] -= w[index];
			if (p[i] <= 0) nnum += 1;
			int temp = dfs(index + 1, nnum);
			ok = true;
			p[index] += w[i];
			p[i] += w[index];
			if (ans < temp) ans = temp;
		}
	}
	if (!ok) {
		int temp = dfs(index + 1, num);
		if (ans < temp) ans = temp;
	}
	return ans;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> w[i];
	}
	cout << dfs(0, 0);
	return 0;
}
