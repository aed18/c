#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    int population, commands;

    while (cin >> population >> commands && (population || commands)) {
        deque<int> queue;
        for (int i = 1; i <= min(population, commands); ++i) {
            queue.push_back(i);
        }
        cout << "Case " << ++t << ":\n";

        for (int i = 0; i < commands; ++i) {
            char cmd;
            cin >> cmd;

            if (cmd == 'N') {
                int current = queue.front();
                cout << current << '\n';
                queue.pop_front();
                queue.push_back(current);
            }
            else { 
                int x;
                cin >> x;
                auto it = find(queue.begin(), queue.end(), x);
                if (it != queue.end()) {
                    queue.erase(it);
                }
                queue.push_front(x);
            }
        }
    }

    return 0;
}
