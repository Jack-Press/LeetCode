class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);
        int p1 = 0, len = 0;

        for (int p2 = 0; p2 < s.length(); p2++) {
            if (lastSeen[s[p2]] >= p1) {
                p1 = lastSeen[s[p2]] + 1;
            }
            lastSeen[s[p2]] = p2;
            len = max(len, p2 - p1 + 1);
        }

        return len;
    }
};