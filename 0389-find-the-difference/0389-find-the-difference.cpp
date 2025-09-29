class Solution {
public:
    char findTheDifference(const string& s, const string& t) {
        unordered_map<char, int> chars;
        chars.reserve(s.size());

        for(char c : s){
            if(chars.count(c)){
                chars[c]++;
            }
            else{
                chars[c] = 1;
            }
        }

        for(char c : t){
            if(chars.count(c) && chars[c] != 0){
                chars[c]--;
            }
            else{
                return c;
            }
        }

        return 'a';
    }
};