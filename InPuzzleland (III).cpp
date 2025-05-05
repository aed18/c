#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> g[26];
char path[32];
int n, m, st, ed, used[26];
int bused[26] = {}, tused = 0;

bool bfs(int u, int comp) {
    tused++;
    int cnt = 0;
    queue<int> Q;
    Q.push(u);
    bused[u] = tused;

    while (!Q.empty()) {
        u = Q.front(); Q.pop();
        cnt++;
        for (int v : g[u]) {
            if (bused[v] != tused && used[v] == 0) {
                bused[v] = tused;
                Q.push(v);
            }
        }
    }
    return cnt == comp;
}

bool dfs(int idx, int u) {
    path[idx] = u + 'A';
    if (idx < n - 1 && used[ed]) return false;

    if (idx == n - 1) {
        path[n] = '\0';
        cout << path << '\n';
        return true;
    }

    for (int v : g[u]) {
        if (used[v] || !bfs(v, n - idx - 1)) continue;
        used[v] = 1;
        if (dfs(idx + 1, v)) return true;
        used[v] = 0;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, cases = 0;
    cin >> T;

    while (T--) {
        cin >> n >> m;
        vector<string> name(n);
        string s1, s2;
        int mg[26][26] = {};

        for (int i = 0; i < 26; i++) g[i].clear();

        for (int i = 0; i < n; i++) {
            cin >> name[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> s1 >> s2;
            int x = s1[0] - 'A';
            int y = s2[0] - 'A';
            mg[x][y] = mg[y][x] = 1;
        }

        st = name[0][0] - 'A';
        ed = name[n - 1][0] - 'A';

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (mg[i][j]) g[i].push_back(j);
            }
        }

        cout << "Case " << ++cases << ": ";
        memset(used, 0, sizeof(used));
        used[st] = 1;

        if (!dfs(0, st)) {
            cout << "impossible\n";
        }
    }

    return 0;
}
