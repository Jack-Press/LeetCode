class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();

        // orig will hold the water level, start as terrain height
        vector<vector<int>> orig = heightMap;

        bool updated = true, firstPass = true;
        while (updated) {
            updated = false;

            // Forward sweep
            for (int i = 1; i < m - 1; i++) {
                for (int j = 1; j < n - 1; j++) {
                    int val = max(heightMap[i][j], min(orig[i-1][j], orig[i][j-1]));
                    if (firstPass || orig[i][j] > val) {
                        orig[i][j] = val;
                        updated = true;
                    }
                }
            }

            firstPass = false;

            // Backward sweep
            for (int i = m - 2; i >= 1; i--) {
                for (int j = n - 2; j >= 1; j--) {
                    int val = max(heightMap[i][j], min(orig[i+1][j], orig[i][j+1]));
                    if (orig[i][j] > val) {
                        orig[i][j] = val;
                        updated = true;
                    }
                }
            }
        }

        // Compute trapped water
        int res = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                res += orig[i][j] - heightMap[i][j];
            }
        }
        return res;
    }
};
