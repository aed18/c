#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr double ERROR = 1e-8;

typedef pair<double, double> Speed; 

int n;
double totalDistance;
Speed speeds[20];

double getTime(const Speed& s, const pair<double, double>& length) {
    return length.first / s.first + length.second / s.second;
}

double getLargestDifference(double runDistance) {
    double minTime = 1e9;
    pair<double, double> segmentLengths = { runDistance, totalDistance - runDistance };

    double cheaterTime = getTime(speeds[n - 1], segmentLengths);

    for (int i = 0; i < n - 1; ++i) {
        minTime = min(minTime, getTime(speeds[i], segmentLengths));
    }

    return (cheaterTime - minTime) * 3600.0; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> totalDistance) 
    {
        cin >> n;
        for (int i = 0; i < n; ++i) 
        {
            cin >> speeds[i].first >> speeds[i].second;
        }

        double left = 0.0, right = totalDistance;

        while (fabs(right - left) > ERROR) 
        {
            double m1 = (2 * right + left) / 3.0;
            double m2 = (right + 2 * left) / 3.0;

            if (getLargestDifference(m2) < getLargestDifference(m1)) {
                right = m1;
            }
            else {
                left = m2;
            }
        }

        double diff = getLargestDifference(left);

        if (diff > 0) 
        {
            cout << "The cheater cannot win.\n";
        }
        else 
        {
            cout << "The cheater can win by " << (int)round(-diff)
                << " seconds with r = " << fixed << setprecision(2) << left
                << "km and k = " << fixed << setprecision(2) << (totalDistance - left)
                << "km.\n";
        }
    }

    return 0;
}
