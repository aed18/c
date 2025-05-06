vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
    vector<vector<int>> widthByHeight(101);  // heights 1..100

    for (auto& r : rectangles) {
        int w = r[0], h = r[1];
        widthByHeight[h].push_back(w);
    }

    for (int h = 1; h <= 100; ++h)
        sort(widthByHeight[h].begin(), widthByHeight[h].end());

    vector<int> result;

    for (auto& p : points) {
        int x = p[0], y = p[1];
        int count = 0;

        for (int h = y; h <= 100; ++h) {
            auto& widths = widthByHeight[h];
            count += widths.end() - lower_bound(widths.begin(), widths.end(), x);
        }

        result.push_back(count);
    }

    return result;
}
