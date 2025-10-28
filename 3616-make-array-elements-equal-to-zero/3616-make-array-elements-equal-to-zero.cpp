class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int right = 0;
        for(int num : nums){
            right += num;
        }

        int res = 0, n = nums.size(), left = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0 && abs(left - right) < 2){
                if(left == right){
                    res += 2;
                }
                else if(abs(left - right) == 1){
                    res++;
                }
            }
            else{
                left += nums[i];
                right -= nums[i];
            }
        }

        return res;
    }
};