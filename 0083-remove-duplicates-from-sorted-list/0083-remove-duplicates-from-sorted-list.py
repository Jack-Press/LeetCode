# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode | None) -> ListNode | None:
        hashmap = {}
        while head:
            hashmap[head.val] = head.val
            head = head.next

        cur = None
        for num in reversed(list(hashmap.keys())):
            cur = ListNode(num, cur)
        return cur