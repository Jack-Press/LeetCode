class Solution {
public:
    string digitSum(string& s, int k) {
        int n = s.size();
        while(n > k){
            int currChar = 0;
            string temp = "";
            while(currChar < n){
                int total = 0;
                if(n > currChar + k){
                    for(char c : s.substr(currChar, k)){
                        total += c - '0';
                    }
                }
                else{
                    for(char c : s.substr(currChar)){
                        total += c - '0';
                    }
                }
                temp.append(to_string(total));
                currChar += k;
            }
            s = temp;
            n = s.size();
        }

        return s;
    }
};