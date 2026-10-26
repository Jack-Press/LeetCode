class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        appeared = {}

        for num in nums:
            if num in appeared:
                return True
            appeared[num] = False
        return False