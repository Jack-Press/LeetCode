class Solution {
public:
    int maximumEnergy(vector<int>& energy, const int k) {
        int highest = energy.back();
        const int n = energy.size() - 1;
        for(int i = 0; i < k; i++){
            int j = n - i;
            while(j >= 0){
                if(j < n - k + 1){
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