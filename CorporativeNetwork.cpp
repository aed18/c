#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> parent, dist;

int find(int x) {
    if (x == parent[x]) return x;
    int p = find(parent[x]);
    dist[x] += dist[parent[x]];
    return parent[x] = p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcase;
    cin >> testcase;

    while (testcase--) {
        int n;
        cin >> n;

        parent.assign(n + 1, 0);
        dist.assign(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        string cmd;
        while (cin >> cmd && cmd != "O") {
            int x, y;
            if (cmd == "E") {
                cin >> x;
                find(x);
                cout << dist[x] << '\n';
            }
            else if (cmd == "I") {
                cin >> x >> y;
                parent[x] = y;
                dist[x] = abs(x - y) % 1000;
            }
        }
    }

    return 0;
}
