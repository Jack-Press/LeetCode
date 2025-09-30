class Solution {
public:
    int triangularSum(vector<int>& nums) {
        const int len = nums.size() - 1;
        for(int i = len; i >= 0; i--){
            for(int j = 0; j < i; j++){
                nums[j] += nums[j + 1];
                nums[j] %= 10;
            }
        }
        return nums[0];
    }
};