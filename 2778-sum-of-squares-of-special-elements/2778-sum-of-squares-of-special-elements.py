class Solution(object):
    def sumOfSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        if n == 1:
            return nums[0] * nums[0]

        sum = nums[-1] * nums[-1] + nums[0] * nums[0]

        for i in range(1, (n+1)/2):
            if n%(i+1) == 0:
                sum = sum + nums[i] * nums[i]
        
        return sum