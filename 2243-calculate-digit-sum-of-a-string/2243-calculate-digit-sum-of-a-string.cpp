class Solution {
public:
    string digitSum(string s, int k) {
        string res = s;
        int n = res.size();
        while(n > k){
            int currChar = 0;
            string temp = "";
            while(currChar < n){
                int total = 0;
                if(n > currChar + k){
                    for(char c : res.substr(currChar, k)){
                        total += c - '0';
                    }
                }
                else{
                    for(char c : res.substr(currChar)){
                        total += c - '0';
                    }
                }
                temp.append(to_string(total));
                currChar += k;
            }
            res = temp;
            n = res.size();
        }

        return res;
    }
};