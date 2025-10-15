class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size(), res = 1, prevLen = 0, currLen = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currLen++;
            } else {
                res = max(max(res, currLen / 2), min(prevLen, currLen));
                prevLen = currLen;
                currLen = 1;
            }
        }

        res = max(max(res, currLen / 2), min(prevLen, currLen));
        return res;
    }
};
