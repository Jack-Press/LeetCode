class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int len = 1;
        string longest = s.substr(0,1);

        for (int l = 0; l < s.size(); l++) {
            for (int r = l; r < s.size(); r++) {
                bool isPalindrome = true;
                int left = l, right = r;
                while (left < right) {
                    if (s[left] != s[right]) {
                        isPalindrome = false;
                        break;
                    }
                    left++;
                    right--;
                }
                if (isPalindrome && (r - l + 1) > len) {
                    len = r - l + 1;
                    longest = s.substr(l, len);
                }
            }
        }
        return longest;
    }
};
