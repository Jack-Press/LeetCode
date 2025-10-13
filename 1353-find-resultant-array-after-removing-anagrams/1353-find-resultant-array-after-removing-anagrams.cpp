class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        array<uint8_t, 26> curr{0};
        for(char c : words[0]){
            curr[c - 'a']++;
        }

        vector<string> res;
        res.reserve(words.size());
        res.push_back(words[0]);
        array<uint8_t, 26> next;

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