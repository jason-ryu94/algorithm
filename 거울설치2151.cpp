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
int n, sx, sy, ex, ey;
char a[50][50];
int d[50][50];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
queue<tuple<int, int, int>> q;

void go(int x, int y, int dir, int k) {
	while (true) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
		if (a[nx][ny] == '*') break;
		if (a[nx][ny] == '!') q.push(make_tuple(nx, ny, dir));
		if (d[nx][ny] == -1) d[nx][ny] = k;
		x = nx;
		y = ny;
	}
}


int main() {
	cin >> n;
	memset(d, -1, sizeof(d));
	sx = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				if (sx == -1) {
					sx = i;
					sy = j;
				}
				else {
					ex = i;
					ey = j;
				}
			}
		}
	}
	q.push(make_tuple(sx, sy, -1));
	d[sx][sy] = 0;
	while (!q.empty()) {
		int x, y, dir;
		tie(x, y, dir) = q.front();
		q.pop();
		if (dir == -1 || dir == 0 || dir == 1) {
			go(x, y, 2, d[x][y] + 1);
			go(x, y, 3, d[x][y] + 1);
		}
		if (dir == -1 || dir == 2 || dir == 3) {
			go(x, y, 0, d[x][y] + 1);
			go(x, y, 1, d[x][y] + 1);
		}
		if (d[ex][ey] != -1) break;
	}
	cout << d[ex][ey]-1;
	return 0;

}
