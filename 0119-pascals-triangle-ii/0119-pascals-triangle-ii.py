class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]
        
        temp = [1]* (rowIndex + 1)
        res = [1]*(rowIndex + 1)

        for i in range(2,rowIndex + 1):
            for j in range(1,i):
                res[j] = temp[j] + temp[j - 1]

            temp = res[:]

        return res