class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        BSTs = [0] * (n+1)
        BSTs[0] = 1
        BSTs[1] = 1
        for i in range(2,(n+1)):
            for j in range(i):
                BSTs[i] += BSTs[j] * BSTs[i-1-j]

        return BSTs[-1]
        