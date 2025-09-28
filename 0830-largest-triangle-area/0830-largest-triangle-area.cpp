class Solution {public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxA = 0.0;
        int len = points.size();

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                for (int k = j + 1; k < len; k++) {
                    double a = Dist(points[i], points[j]);
                    double b = Dist(points[j], points[k]);
                    double c = Dist(points[k], points[i]);

                    double S = (a + b + c) / 2.0;
                    S = S * (S - a) * (S - b) * (S - c);

                    if (S < 0) S = 0.0;

                    maxA = max(maxA, sqrt(S));
                }
            }
        }
        return maxA;
    }

private:
    double Dist(const vector<int>& p1, const vector<int>& p2) {
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return sqrt(dx * dx + dy * dy);
    }
};