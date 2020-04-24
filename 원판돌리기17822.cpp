#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m, t;
vector<vector<int>> a(51, vector<int>(51, 0));
bool d[51][51];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<int> rotation(vector<int> p, int dir, int k) {
	vector<int> b(m, 0);
	if (dir == 0) {
		for (int i = k; i < m; i++) {
			b[i] = p[i - k];
		}
		for (int i = m - k; i < m; i++) {
			b[i - (m - k)] = p[i];
		}
	}
	else {
		for (int i = k; i < m; i++) {
			b[i - k] = p[i];
		}
		for (int i = 0; i < k; i++) {
			b[i + m - k] = p[i];
		}
	}
	return b;
}

void go(vector<vector<int>>& a) {
	memset(d, false, sizeof(d));
	bool tr = false;  // 지우는 수가 있는지 확인
	int sum = 0;
	int alive = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += a[i][j];
			if (a[i][j] == 0) continue;
			alive += 1;
			if (d[i][j]) continue;
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			d[i][j] = true;
			int num = a[i][j];
			bool ok = false;
			while (!q.empty()) {
				int x, y;
				tie(x, y) = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || nx >= n) continue;
					if (ny < 0 || ny >= m) {
						if (ny < 0) ny = m - 1;
						else {
							ny = 0;
						}
					}
					if (d[nx][ny]) continue;
					if (a[nx][ny] == num) {
						if (!ok) {
							a[x][y] = 0;
							ok = true;
							tr = true;
						}
						a[nx][ny] = 0;
						d[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	
	if (!tr) {
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) continue;
				if (a[i][j]*alive == sum) continue;
				else if (a[i][j]*alive > sum) a[i][j] -= 1;
				else if (a[i][j]*alive < sum) a[i][j] += 1;
			}
		}
	}
}


int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < t; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		for (int j = x; j <= n ; j += x) {
			a[j - 1] = rotation(a[j - 1], d, k);
		}
		if (i == 2) {
			int kkk = 1;
		}
		go(a);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) continue;
			ans += a[i][j];
		}
	}
	cout << ans;
	
	return 0;
}
