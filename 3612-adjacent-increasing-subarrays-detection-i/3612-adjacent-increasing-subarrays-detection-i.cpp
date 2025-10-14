class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i <= n - 2 * k; i++) {
            bool inc = true;
            for (int j = 0; j < k - 1; j++) {
                if (nums[i + j] >= nums[i + j + 1] || nums[i + k + j] >= nums[i + k + j + 1]) {
                    inc = false;
                    i += j;
                    break;
                }
            }
            if (inc) return true;
        }
        return false;
    }
};
