class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int highest = energy.back();
        int n = energy.size();
        for(int i = 0; i < k; i++){
            int j = n - i - 1;
            while(j >= 0){
                if(j < n - k){
                    energy[j] += energy[j + k];
                }
                if(energy[j] > highest){
                    highest = energy[j];
                }
                j -= k;
            }
        }
        return highest;
    }
};