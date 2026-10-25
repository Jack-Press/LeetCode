import math

class Solution:
    def permuteUnique(self, nums: list[int]) -> list[list[int]]:
        n = len(nums)
        hashmap = {}
        
        def permutation(i: int):
            if i == n:
                hashmap[str(nums)] = nums[:]
                return 

            for j in range(i,n):
                nums[i], nums[j] = nums[j], nums[i]
                permutation(i+1)
                nums[i], nums[j] = nums[j], nums[i]

        permutation(0)
        return list(hashmap.values())