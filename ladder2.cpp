#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
int a[101][101];
int n = 100;
int m = 100;
int dx[] = { 0, 0, 1 };
int dy[] = { 1, -1, 0 };

int go(int x, int y, int yx, int yy, int cnt) {
	if (x == n -1) return cnt;
	int nx, ny;
	for (int k = 0; k < 3; k++) {
		nx = x + dx[k];
		ny = y + dy[k];
		if (nx >= n || ny < 0 || ny >= m) continue;
		if (a[nx][ny] != 1) continue;
		if (nx == yx && ny == yy) continue;
		break;
	}
	return go(nx, ny, x, y, cnt + 1);
}


int main() {
	
	for (int t = 1; t <= 10; t++) {
		int tc;
		cin >> tc;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		int ans = -1;
		int num = -1;
		for (int i = 0; i < n; i++) {
			if (a[0][i] == 0) continue;
			int temp = go(0, i, -1, -1, 0);
			if ( num == -1 || temp <= num) {
				ans = i;
				num = temp;
			}
		}
		cout << "#" << t << ' ' << ans << '\n';
	}
	return 0;
}
// 각 곱하기 에서 두 수로 나눠서 다이나믹 진행
