#include <iostream>
#include <queue>
#include <deque>;
#include <vector>
#include <cstring>
#include <tuple>
#include <cstdlib>
#include <algorithm>
#include <tuple>
#include <set>
#include <string>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;
int n, m, p;
int s[10];
int a[1000][1000];
int d[1000][1000];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


int main() {
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) {
		cin >> s[i];
	}
	queue<pair<int, int>> player[10];
	memset(d, -1, sizeof(d));
	memset(a, -1, sizeof(a));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			if (x == '.') {
				a[i][j] = 0;

			}
			else if (x == '#') {
				a[i][j] = -1;
			}
			else {
				a[i][j] = x - '0';
				player[a[i][j]].push(make_pair(i, j));
				d[i][j] = 0;
			}
		}
	}
	bool ok = true;
	while (ok) {
		ok = false;
		for (int i = 1; i <= p; i++) {
			int u, v;
			if (player[i].empty()) continue;
			tie(u, v) = player[i].front();
			int num = d[u][v];
			num += s[i];
			while (!player[i].empty()) {
				int x, y;
				tie(x, y) = player[i].front();
				if (d[x][y] == num) break;
				player[i].pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (d[nx][ny] != -1) continue;
					if (a[nx][ny] != 0) continue;
					a[nx][ny] = i;
					d[nx][ny] = d[x][y] + 1;
					player[i].push(make_pair(nx, ny));
					ok = true;
				}
			}
		}		
	}
	int ans[10] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == -1) continue;
			ans[a[i][j]] += 1;
		}
	}
	for (int i = 1; i <= p; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
