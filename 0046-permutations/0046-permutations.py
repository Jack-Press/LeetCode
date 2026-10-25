import math

class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        n = len(nums)
        f = math.factorial(n)
        perms = [[] * n] * f

        def permutation(i: int, current: int) -> int:
            if i == n:
                perms[current] = nums[:]
                current = current + 1
                return current

            for j in range(i, n):
                nums[i], nums[j] = nums[j], nums[i]
                current = permutation(i + 1, current)
                nums[i], nums[j] = nums[j], nums[i]
            return current

        permutation(0, 0)

        return perms