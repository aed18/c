#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    while (cin >> t && t != 0) {
        vector<string> result(t, "");
        vector<bool> occupied(t, false);
        int pos = 0;

        for (int i = 0; i < t; ++i) {
            string card, word;
            cin >> card >> word;
            int len = word.length();

            for (int count = 0; count < len;) {
                if (!occupied[pos]) ++count;
                if (count == len) break;
                pos = (pos + 1) % t;
            }

            result[pos] = card;
            occupied[pos] = true;

            for (int j = 0; j < t; ++j) {
                pos = (pos + 1) % t;
                if (!occupied[pos]) break;
            }
        }

        for (int i = 0; i < t; ++i) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << "\n";
    }
    return 0;
}
