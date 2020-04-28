#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m;
deque<int> q;
vector<int> a;
int ans = -1;

void left() {
	int x = q.front();
	q.pop_front();
	q.push_back(x);
}

void right() {
	int x = q.back();
	q.pop_back();
	q.push_front(x);
}


int dfs(int cnt, int index, int ork) { // 브루트 포스는 실패
	if (index == m) {
		return cnt;
	}
	if (ans != -1 && ans < cnt) return -1;

	if (q.front() == a[index]) {
		int x = q.front();
		q.pop_front();
		int temp = dfs(cnt, index + 1, -1);
		if (temp != -1 && (ans == -1 || temp < ans)) ans = temp;
		q.push_front(x);
	}
	else if (ork == 0) {
		right();
		int temp = dfs(cnt + 1, index, 0);
		if (temp != -1 && (ans == -1 || temp < ans)) ans = temp;
		left();
	}
	else if(ork == 1) {
		left();
		int temp = dfs(cnt + 1, index, 1);
		if (temp != -1 && (ans == -1 || temp < ans)) ans = temp;
		right();
	}
	else if (ork == -1) {
		left();
		int temp = dfs(cnt + 1, index, 1);
		if (temp != -1 && (ans == -1 || temp < ans)) ans = temp;
		right();
		right();
		temp = dfs(cnt + 1, index, 0);
		if (temp != -1 && (ans == -1 || temp < ans)) ans = temp;
		left();
	}
	return ans;
}


int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	int num = 0;
	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}
	bool ok = true;
	int index = 0;
	int aaa = 0;
	while (ok) {
		if (index == m) break;
		if (q.front() == a[index]) {
			q.pop_front();
			index += 1;
		}
		else {
			int num = q.size();
			int order = 0;
			for (int i = 0; i < num; i++) {
				if (q.at(i) == a[index]) {
					order = i;
					break;
				}
			}
			if (order >= num - order) {
				for (int i = 0; i < num - order; i++) {
					right();
					aaa += 1;
				}
			}
			else {
				for (int i = 0; i < order; i++) {
					left();
					aaa += 1;
				}
			}
		}
	}
	int an = 0;
	//an = dfs(0, 0, -1);
	cout << aaa;

	return 0;
}

