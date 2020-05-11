#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>


using namespace std;
int n;
vector<string> a;
bool d[200];

bool cmp(string x, string y) {
    return x.length() < y.length();
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n - 2; i++) {
        string x;
        cin >> x;
        a.push_back(x);
    }
    vector<string> b(a);
    sort(a.begin(), a.end(), cmp);
    string x = a[2 * n - 3];
    string y = a[2 * n - 4];
    string x1, y1, x2, y2;
    x1 = x.substr(0, n - 2);
    x2 = x.substr(1, n - 2);
    y1 = y.substr(0, n - 2);
    y2 = y.substr(1, n - 2);
    bool ok = false;
    string all;
    if (x1 == y2) {
        all = y + x[n - 2];

        for (int i = 0; i < n - 1; i++) {
            int num = a[2 * i].size();
            if (all.substr(0, num) == a[2 * i] && all.substr(n - num, num) == a[2 * i + 1]) {
                ok = true;
            }
            else if (all.substr(0, num) == a[2 * i + 1] && all.substr(n - num, num) == a[2 * i]) {
                ok = true;
            }
            else {
                ok = false;
                break;
            }
        }

    }
    if (!ok) all = x + y[n - 2];
    cout << all << '\n';
    memset(d, false, sizeof(d));
    for (int i = 0; i < 2 * n - 2; i++) {
        if (all.substr(0, b[i].size()) == b[i] && !d[b[i].length()]) {
            d[b[i].length()] = true;
            cout << "P";
        }
        else {
            cout << "S";
        }
    }
    return 0;

}
