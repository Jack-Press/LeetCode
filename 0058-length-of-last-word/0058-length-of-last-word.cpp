class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n-1;
        int count = 0;
        while(s[i] == ' '){
            i--;
        }
        while(i >= 0 && s[i] != ' '){
            i--;
            count++;
        }

        return count;
    }
};