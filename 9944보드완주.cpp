#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <tuple>


using namespace std;
int n, m;
int a[30][30];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool d[30][30];
int ru;
int ans = -1;


tuple<int, int, int> go(int x, int y, int dir) {
    int temp = 0;
    while (true ) {
        d[x][y] = true;
        x += dx[dir];
        y += dy[dir];
        temp += 1;
        if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 1 || d[x][y]) break;
    }
    return make_tuple(x-dx[dir], y-dy[dir], temp-1);
}



int dfs(int x, int y, int cnt, int num) {
    if (num == ru) return cnt;
    bool ok = true;
    int an = -1;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (d[nx][ny]) continue;
        if (a[nx][ny] == 1) continue;
        ok = false;
        int z;
        tie(nx, ny, z) = go(x, y, k);
        int temp = dfs(nx, ny, cnt + 1, num + z);
        int tx = nx;
        int ty = ny;
        for (int i = 0; i < z; i++) {
            d[tx][ty] = false;
            tx -= dx[k];
            ty -= dy[k];
        }
        if (temp == -1) continue;
        if (an == -1 || an > temp) an = temp;


    }
    if (ok) return -1;
    return an;
}


int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t = 1;
    while(cin >> n >> m) {
        memset(d, false, sizeof(d));
        ru = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char e;
                cin >> e;
                if (e == '.') {
                    a[i][j] = 0;
                    ru += 1;
                }
                else a[i][j] = 1;
            }
        }

        int kk = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) continue;
                memset(d, false, sizeof(d));
                int temp = dfs(i, j, 0, 1);
                if (temp == -1) continue;
                if (kk == -1 || kk > temp) kk = temp;
            }
        }

        cout << "Case" << t << ' ' <<kk << '\n';
        t++;
    }
    return 0;
}
