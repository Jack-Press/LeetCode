class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 1;
        }

        int res = 1;
        int curr = 1;
        bool inc = false;

        if(nums[0] < nums[1]){
            inc = true;
        }

        for(int i=1;i<nums.size();i++){
            if((nums[i] > nums[i-1] && inc) || (nums[i] < nums[i-1] && !inc)){
                curr++;
            }
            else{
                inc = !inc;
                if(curr > res){
                    res = curr;
                }
                if(nums[i] == nums[i-1]){
                    curr = 1;
                }
                else{
                    curr = 2;
                }
            }
        }
        if(curr > res){
            res = curr;
        }

        return res;
    }
};