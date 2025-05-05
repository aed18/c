#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    int t, cases = 0;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> subjects(n);
        vector<int> deadlines(n);

        for (int i = 0; i < n; i++) {
            cin >> subjects[i] >> deadlines[i];
        }

        int actualDeadline;
        string subjectToCheck;
        cin >> actualDeadline >> subjectToCheck;

        cout << "Case " << ++cases << ": ";

        bool found = false;
        for (int i = 0; i < n; i++) {
            if (subjects[i] == subjectToCheck) {
                found = true;
                if (actualDeadline >= deadlines[i])
                    cout << "Yesss\n";
                else if (actualDeadline + 5 >= deadlines[i])
                    cout << "Late\n";
                else
                    cout << "Do your own homework!\n";
                break;
            }
        }

        if (!found)
            cout << "Do your own homework!\n";
    }

    return 0;
}
