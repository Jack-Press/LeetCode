class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        vector<string> res;
        res.reserve(nums.size());
        while(i < n){
            int j = i + 1;
            if(i == n - 1 || nums[i] + 1 != nums[j]){
                res.push_back(to_string(nums[i]));
            }
            else{
                while(j + 1 < n && nums[j] + 1 == nums[j + 1]){
                    j++;
                }
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
                j++;
            }
            i = j;
        }
        return res;
    }
};