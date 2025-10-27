class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, prev = 0, curr = 0;
        for(string b : bank){
            curr = 0;
            for(char c : b){
                if(c == '1'){
                    curr++;
                }
            }

            if(curr != 0){
                res += curr * prev;
                prev = curr;
            }
        }
        return res;
    }
};