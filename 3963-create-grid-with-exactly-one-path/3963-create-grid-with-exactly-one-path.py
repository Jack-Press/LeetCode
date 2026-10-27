class Solution(object):
    def createGrid(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: List[str]
        """
        res = [("#" * (n - 1)) + "."] * m
        res[0] = "." * n

        return res