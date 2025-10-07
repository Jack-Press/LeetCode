class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> full;
        vector<int> lastDry;
        lastDry.reserve(rains.size());
        vector<int> res;
        res.reserve(rains.size());

        for (int i = 0; i < rains.size(); i++) {
            int lake = rains[i];

            if (lake == 0) {
                lastDry.push_back(i);
                res.push_back(1); // placeholder
            } 
            else if (!full.contains(lake)) {
                full[lake] = i;
                res.push_back(-1);
            } 
            else {
                if (lastDry.empty()) return {}; // no dry day available

                bool dried = false;
                for (int j = 0; j < lastDry.size(); j++) {
                    if (lastDry[j] > full[lake]) { // must dry after last full
                        res[lastDry[j]] = lake;
                        full[lake] = i; // record last full day (NOT -1)
                        lastDry.erase(lastDry.begin() + j);
                        dried = true;
                        break;
                    }
                }
                if (!dried) return {}; // no valid dry day found
                res.push_back(-1);
            }
        }
        return res;
    }
};
