class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<uint8_t> curr(26, 0);
        for(char c : words[0]){
            curr[c - 'a']++;
        }

        vector<string> res;
        res.reserve(words.size());
        res.push_back(words[0]);
        vector<uint8_t> next(26, 0);

        for (int i = 1; i < words.size(); i++) {
            for(int i = 0; i < next.size(); i++){
                next[i] = 0;
            }

            for(char c : words[i]){
                next[c - 'a']++;
            }

            if(curr != next){
                res.push_back(words[i]);
                curr = next;
            }
        }

        return res;
    }
};