#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int n, m;
        cin >> n >> m;

        vector<string> names(n);
        vector<int> freq(n);
        set<pair<int, int>> S;

        for (int i = 0; i < n; ++i) {
            cin >> names[i] >> freq[i];
            S.insert({ freq[i], i });
        }

        for (int i = 0; i < m; ++i) {
            auto t = *S.begin();
            S.erase(t);
            cout << t.first << " " << names[t.second] << "\n";
            S.insert({ t.first + freq[t.second], t.second });
        }
    }

    return 0;
}
