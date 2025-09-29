class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int len = values.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for (int i = 3; i <= len; i++) {
            for (int j = 0; j + i - 1 < len; j++) {
                int k = j + i - 1;
                int minimum = INT_MAX;
                for (int l = j + 1; l < k; l++) {
                    int cost = dp[j][l] + dp[l][k] + values[j] * values[l] * values[k];
                    if (cost < minimum) minimum = cost;
                }
                dp[j][k] = minimum;
            }
        }
        return dp.empty() ? 0 : dp[0][len-1];
    }
};