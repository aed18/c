#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, cases = 0;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<long long> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            A[i] = -A[i]; 
        }

        for (int i = 0; i < n; ++i) {
            long long y;
            cin >> y;
            A[i] += y; 
        }

        sort(A.begin(), A.end(), greater<long long>());

        int count = 0;
        for (int i = n - 1; i >= 0 && count < m; --i) {
            if (A[i] < 0) {
                --n;
                ++count;
            }
            else {
                break;
            }
        }

        long long profit = 0;
        for (int i = 0; i < n; ++i) {
            profit += A[i];
        }

        cout << "Case " << ++cases << ": ";
        if (profit <= 0) {
            cout << "No Profit" << '\n';
        }
        else {
            cout << profit << '\n';
        }
    }

    return 0;
}
