#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;
char a[12][6];
int n = 12;
int m = 6;
bool d[12][6];
char order[5] = { 'R', 'G','B', 'P', 'Y' };
queue<pair<int, int>> q[5];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool bfs() {
	bool ok = false;
	for (int i = 0; i < 5; i++) {
		
		while (!q[i].empty()) {
			queue<pair<int, int>> qq;
			int u, v;
			tie(u, v) = q[i].front();
			q[i].pop();
			if (d[u][v]) continue;
			queue<pair<int, int>> tempq;
			tempq.push(make_pair(u, v));
			while (!tempq.empty()) {
				int x, y;
				tie(x, y) = tempq.front();
				tempq.pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (d[nx][ny]) continue;
					if (a[nx][ny] != order[i]) continue;
					qq.push(make_pair(nx, ny));
					d[nx][ny] = true;
					tempq.push(make_pair(nx, ny));
				}
			}
			if (qq.size() >= 4) {
				while (!qq.empty()) {
					int x, y;
					tie(x, y) = qq.front();
					qq.pop();
					a[x][y] = '.';
				}
				ok = true;
			}

		}
		
	}	
	return ok;
}
void down() {
	for (int j = 0; j < m; j++) {
		int tum = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i][j] == '.') tum += 1;
			else {
				char temp = a[i][j];
				a[i][j] = '.';
				a[i + tum][j] = temp;
				if (temp == 'R') {
					q[0].push(make_pair(i + tum, j));
				}
				else if (temp == 'G') {
					q[1].push(make_pair(i + tum, j));
				}
				else if (temp == 'B') {
					q[2].push(make_pair(i + tum, j));
				}
				else if (temp == 'P') {
					q[3].push(make_pair(i + tum, j));
				}
				else if (temp == 'Y') {
					q[4].push(make_pair(i + tum, j));
				}

			}
		}
	}
}



int main() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '.') continue;
			else if (a[i][j] == 'R') {
				q[0].push(make_pair(i, j));
			}
			else if (a[i][j] == 'G') {
				q[1].push(make_pair(i, j));
			}
			else if (a[i][j] == 'B') {
				q[2].push(make_pair(i, j));
			}
			else if (a[i][j] == 'P') {
				q[3].push(make_pair(i, j));
			}
			else if (a[i][j] == 'Y') {
				q[4].push(make_pair(i, j));
			}
		}
	}
	bool ok = true;
	int ans = 0;
	while (ok) {
		memset(d, false, sizeof(d));
		ok = bfs();
		down();
		if (ok) ans += 1;
	}
	


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
	cout << ans;
	return 0;
}
