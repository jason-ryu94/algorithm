#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;
char a[50][50];
int n;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int check() {
	bool c[n][n];
	memset(c, false, sizeof(c));
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
		    int cnt = 1;
		    if(c[i][j]) continue;
			c[i][j] = true;			
			for(int k = 0; k < 2; k++) {
			    int nx = i + dx[k];
				int ny = j + dx[k];
				if(nx < 0 || nx>= n|| ny <0 || ny >= 0) continue;
				if(a[i][j] != a[nx][ny]) continue;
				if(c[nx][ny]) continue;
				c[nx][ny] = true;
				cnt+= 1;
				while(1) {
					nx += dx[k];
					ny +=dx[k];
					if(nx < 0 || nx>= n|| ny <0 || ny >= 0) break;
					if(a[i][j] != a[nx][ny]) break;
					if(c[nx][ny]) break;
					cnt += 1;
					c[nx][ny] = true;
				}
			}
			if(cnt > ans) ans = cnt;
			cnt = 1;
			for(int k = 2; k < 4; k++) {
			    int nx = i + dx[k];
				int ny = j + dx[k];
				if(nx < 0 || nx>= n|| ny <0 || ny >= 0) continue;
				if(a[i][j] != a[nx][ny]) continue;
				if(c[nx][ny]) continue;
				c[nx][ny] = true;
				cnt+= 1;
				while(1) {
					nx += dx[k];
					ny +=dx[k];
					if(nx < 0 || nx>= n|| ny <0 || ny >= 0) break;
					if(a[i][j] != a[nx][ny]) break;
					if(c[nx][ny]) break;
					cnt += 1;
					c[nx][ny] = true;
				}
			}
			if(cnt > ans) ans = cnt;
			
		}
	}
	return ans;
}

int che() {
	int ans = 0;
	bool d[n][n];
	memset(d, false, sizeof(d));
	for(int i = 0; i < n; i++) {
		for(int j= 0; j < n; j++) {
			int cnt = 1;
			if(d[i][j]) continue;
			d[i][j] = true;			
			for(int k = 0; k < 2; k++) {
			    int nx = i;
			    int ny = j;
				while(1) {
					nx += dx[k];
					ny += dy[k];
					if(nx < 0 || nx>= n|| ny <0 || ny >= n) break;
					if(d[nx][ny]) break;
					if(a[i][j] != a[nx][ny]) break;					
					cnt += 1;					
				}
			}
			if(cnt > ans) ans = cnt;
			cnt = 1;
			for(int k = 2; k < 4; k++) {
				int nx = i;
			    int ny = j;
				while(1) {
					nx += dx[k];
					ny += dy[k];
					if(nx < 0 || nx>= n|| ny <0 || ny >= n) break;
					if(d[nx][ny]) break;
					if(a[i][j] != a[nx][ny]) break;					
					cnt += 1;					
				}
			}
			if(cnt > ans) ans = cnt;			
		}
	}
	return ans;
}




int main() {
	cin >> n;
	for(int i= 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			//scanf("%1c", &a[i][j]);
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i+1 <= n-1 && a[i][j] != a[i+1][j]) {
				char temp = a[i][j];
				a[i][j] = a[i+1][j];
				a[i+1][j] = temp;
				int tt = che();
				if(ans < tt) ans = tt;
				a[i+1][j] = a[i][j];
				a[i][j] = temp;
			}
			if(j+1 < n && a[i][j+1] != a[i][j]) {
				char temp = a[i][j];
				a[i][j] = a[i][j+1];
				a[i][j+1] = temp;
				int tt = che();
				if(ans < tt) ans = tt;
				a[i][j+1] = a[i][j];
				a[i][j] = temp;
			}
		}
	}
	cout << ans;
	
	
	

	return 0;
	
}
