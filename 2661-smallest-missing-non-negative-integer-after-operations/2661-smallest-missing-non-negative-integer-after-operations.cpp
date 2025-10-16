class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mods(value, 0);
        for(int num : nums){
            mods[(num % value + value) % value] ++;
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