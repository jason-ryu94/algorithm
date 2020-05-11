#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <map>
#include <array>

using namespace std;

map<array<string, 3>, int> mm;
int dx[] = { 0, 0, 1, 1, 2, 2 };
int dy[] = { 1, 2, 0, 2, 0, 1 };


int main() {
	array<string, 3> s;
	int cnt[3] = { 0, };
	for (int i = 0; i < 3; i++) {
		int x;
		cin >> x;
		if (x == 0) continue;
		cin >> s[i];
		for (int j = 0; j < x; j++) {
			if (s[i][j] == 'A') {
				cnt[0] += 1;
			}
			else if (s[i][j] == 'B') {
				cnt[1] += 1;
			}
			else if (s[i][j] == 'C') {
				cnt[2] += 1;
			}
		}
		
	}

	queue<array<string, 3>> q;
	q.push(s);
	mm[s] = 0;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int x, y;
			x = dx[i];
			y = dy[i];
			if (now[x].length() == 0) continue;
			array<string, 3> next(now);
			next[y].push_back(next[x].back());
			next[x].pop_back();
			if (mm.count(next) != 0) continue;
			mm[next] = mm[now] + 1;
			q.push(next);
		}
	}
	array<string, 3> ans;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			ans[i] += (char)('A' + i);
		}
	}
	cout << mm[ans];
	return 0;

}
