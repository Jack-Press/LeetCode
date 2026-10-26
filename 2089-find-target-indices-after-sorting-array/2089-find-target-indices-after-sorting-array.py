class Solution(object):
    def targetIndices(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        less = 0
        count = 0

        for i in range(len(nums)):
            if nums[i] < target:
                less = less + 1
            if nums[i] == target:
                count = count + 1

        

        return list(range(less, less + count))