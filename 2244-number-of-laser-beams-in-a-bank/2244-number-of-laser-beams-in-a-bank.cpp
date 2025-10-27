class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, prev = 0, curr = 0;
        for(string b : bank){
            curr = 0;
            for(char c : b){
                curr += c - '0';
            }

            res += curr * prev;
            if(curr != 0){
                prev = curr;
            }
        }
        return res;
    }
};