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
bool d[1501][1501];
int dx[] = { 0, 1, 2};
int dy[] = { 1, 2, 0};

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	memset(d, false, sizeof(d));
	int sum = a + b + c;
	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}
	d[a][b] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int x, y, z;
		tie(x, y) = q.front();
		q.pop();
		z = sum - (x + y);
		for (int i = 0; i < 3; i++) {
			int cnt[3] = {x, y, z };
			int u = dx[i];
			int v = dy[i];
			int nx, ny;
			nx = cnt[u];
			ny = cnt[v];
			
			if (nx == ny) continue;
			int temp1 = min(nx, ny)*2;
			int temp2 = max(nx, ny) - min(nx, ny);
			if (cnt[u] > cnt[v]) {
				cnt[u] = temp2;
				cnt[v] = temp1;
			}
			else {
				cnt[u] = temp1;
				cnt[v] = temp2;
			}
			if (d[cnt[0]][cnt[1]]) continue;
			q.push(make_pair(cnt[0], cnt[1]));
			d[cnt[0]][cnt[1]] = true;
		}
	}
	cout << d[sum / 3][sum / 3];
	return 0;

}
