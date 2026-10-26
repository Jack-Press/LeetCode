class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        hashmapS = {}
        hashmapT = {}

        for i in range(len(s)):
            if s[i] in hashmapS:
                if hashmapS[s[i]] != t[i]:
                    return False
            elif (t[i] in hashmapT):
                return False
            hashmapS[s[i]] = t[i]
            hashmapT[t[i]] = s[i]
        return True