#include <iostream>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;

int main() {
    vector<int> dp(100005, INT_MAX);
    dp[0] = 0;

    // Calculamos los factoriales y actualizamos el dp
    for (int i = 1, f = 1; f <= 100000; i++, f *= i) {
        for (int j = f; j <= 100000; j++) {
            dp[j] = min(dp[j], dp[j - f] + 1);
        }
    }


    int N;
    while (cin >> N) {
        cout << dp[N] << endl;
    }

    return 0;
}
