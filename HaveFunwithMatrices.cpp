#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    vector< pair<vector<vector<int>>, int> > answer;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int r = 0; r < n; r++) {
            string line;
            cin >> line;
            for (int c = 0; c < n; c++) {
                matrix[r][c] = line[c] - '0';
            }
        }

        int inst;
        cin >> inst;
        string s;
        for (int k = 0; k < inst; k++) {
            cin >> s;
            if (s == "row") {
                int a, b;
                cin >> a >> b;
                swap(matrix[a - 1], matrix[b - 1]);
            }
            else if (s == "col") {
                int a, b;
                cin >> a >> b;
                for (int r = 0; r < n; r++)
                    swap(matrix[r][a - 1], matrix[r][b - 1]);
            }
            else if (s == "inc") {
                for (int r = 0; r < n; r++)
                    for (int c = 0; c < n; c++)
                        matrix[r][c] = (matrix[r][c] + 1) % 10;
            }
            else if (s == "dec") {
                for (int r = 0; r < n; r++)
                    for (int c = 0; c < n; c++)
                        matrix[r][c] = (matrix[r][c] + 9) % 10;
            }
            else if (s == "transpose") {
                vector<vector<int>> transposed(n, vector<int>(n));
                for (int r = 0; r < n; r++)
                    for (int c = 0; c < n; c++)
                        transposed[r][c] = matrix[c][r];
                matrix = transposed;
            }
        }

        answer.push_back({ matrix, n });
    }

    int caseNum = 1;
    for (auto& a : answer) 
    {
        cout << "Case #" << caseNum++ << endl;
        for (int i = 0; i < a.second; i++) 
        {
            for (int j = 0; j < a.second; j++)
                cout << a.first[i][j];
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
