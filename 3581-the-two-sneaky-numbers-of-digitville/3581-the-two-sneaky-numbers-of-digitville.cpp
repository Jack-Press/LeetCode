class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res(2, -1);
        vector<bool> present(nums.size() - 2, false);
        for(int i : nums){
            if(present[i]){
                if(res[0] == -1){
                    res[0] = i;
                }
                else{
                    res[1] = i;
                    return res;
                }
            }
            else{
                present[i] = true;
            }
        }
        return res;
    }
};