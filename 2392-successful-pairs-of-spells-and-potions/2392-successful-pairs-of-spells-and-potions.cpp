class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); i++) {
            int left = 0, right = potions.size() - 1, idx = potions.size();

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if ((long long)spells[i] * potions[mid] >= success) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            spells[i] = potions.size() - idx;
        }

        return spells;
    }
};