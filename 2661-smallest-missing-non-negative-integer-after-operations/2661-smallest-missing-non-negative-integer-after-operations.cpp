class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mods(value, 0);
        for(int num : nums){
            int r = num % value;
            if (r < 0) r += value;
            mods[r]++;
        }

        int loc = 0;
        for(int i = 1; i < value; i++){
            if(mods[loc] > mods[i]){
                loc = i;
            }
        }

        return mods[loc] * value + loc;
    }
};