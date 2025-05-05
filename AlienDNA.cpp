#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<string> base_sets(n);

        for (int i = 0; i < n; ++i) {
            cin >> base_sets[i];
        }

        int cuts = 0;
        bitset<26> common;
        common.reset();

        for (int i = 0; i < n; ++i) {
            bitset<26> current;
            for (char c : base_sets[i]) {
                current.set(c - 'a');
            }

            if (i == 0) {
                common = current;
            }
            else {
                if ((common & current).any()) {
                    common &= current;
                }
                else {
                    cuts++;
                    common = current; 
                }
            }
        }

        cout << cuts << '\n';
    }

    return 0;
}
