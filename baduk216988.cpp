#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>


using namespace std;
int n, m;
bool d[20][20];
int a[20][20];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	cin >> n >> m;
	vector<pair<int, int>> wq;
	vector<pair<int, int>> bq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				wq.push_back(make_pair(i, j));
			}
			else if (a[i][j] == 2) {
				bq.push_back(make_pair(i, j));
			}
		}
	}
	int num = wq.size();
	vector<int> p(num, 0);
	p[0] = 1;
	p[1] = 1;
	sort(p.begin(), p.end());
	int ans = 0;
	do {
		int x1 = -1;
		int y1, x2, y2;
		for (int i = 0; i < num; i++) {
			if (p[i] == 0) continue;
			int x, y;
			tie(x, y) = wq[i];
			a[x][y] = 1;
			if (x1 == -1) {
				x1 = x;
				y1 = y;
			}
			else {
				x2 = x;
				y2 = y;
			}
		}
		memset(d, false, sizeof(d));		
		bool ok = true;
		int an = 0;
		
		for (int i = 0; i < bq.size(); i++) {
			int x, y;
			tie(x, y) = bq[i];
			if (d[x][y]) continue;
			int temp = 1;
			queue<pair<int, int>> q;
			q.push(make_pair(x, y));
			d[x][y] = true;
			bool ok = true;
			
			while (!q.empty()) {
				int u, v;
				tie(u, v) = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = u + dx[k];
					int ny = v + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (d[nx][ny]) continue;
					if (a[nx][ny] == 0) {
						ok = false;						
						temp = 0;
					}
					else if (a[nx][ny] == 2) {
						d[nx][ny] = true;
						temp += 1;
						q.push(make_pair(nx, ny));
					}
				}				
			}
			if (ok) {
				an += temp;
			}
		
		}
		if (ans < an) ans = an;
		
		a[x1][y1] = 0;
		a[x2][y2] = 0;
	} while (next_permutation(p.begin(), p.end()));
	cout << ans;
	return 0;
}
