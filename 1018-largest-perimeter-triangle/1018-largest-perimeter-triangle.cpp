class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int perim = 0;
        int i = nums.size() - 1;
        for(int i = nums.size() - 1; i > 1; i--){ 
            if(nums[i] < nums[i - 1] + nums[i - 2]){
                perim = nums[i] + nums[i - 1] + nums[i - 2];
                break;
            }
        }
        return perim;
    }
};