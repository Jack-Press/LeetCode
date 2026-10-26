class Solution:
    def isPalindrome(self, s: str) -> bool:
        newS = ""
        for c in s:
            if str.isalnum(c):
                newS = newS + c.lower()

        n = len(newS)
        half = int(n/2)
        for i in range(half):
            if newS[i] != newS[n - 1 - i]:
                return False
        return True