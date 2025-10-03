class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();

        // Keep one copy of the original terrain heights
        const vector<vector<int>> orig = heightMap;

        bool updated = true, firstPass = true;
        while (updated) {
            updated = false;

            // Forward sweep
            for (int i = 1; i < m - 1; i++) {
                for (int j = 1; j < n - 1; j++) {
                    int val = max(orig[i][j], min(heightMap[i-1][j], heightMap[i][j-1]));
                    if (firstPass || heightMap[i][j] > val) {
                        heightMap[i][j] = val;
                        updated = true;
                    }
                }
            }

            firstPass = false;

            // Backward sweep
            for (int i = m - 2; i >= 1; i--) {
                for (int j = n - 2; j >= 1; j--) {
                    int val = max(orig[i][j], min(heightMap[i+1][j], heightMap[i][j+1]));
                    if (heightMap[i][j] > val) {
                        heightMap[i][j] = val;
                        updated = true;
                    }
                }
            }
        }

        // Compute trapped water
        int res = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                res += heightMap[i][j] - orig[i][j];
            }
        }
        return res;
    }
};
