# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode | None, q: TreeNode | None) -> bool:
        
        def checkNode(x: TreeNode | None, y: TreeNode | None) -> bool:
            if (x == None and y == None):
                return True
            if x == None or y == None or x.val != y.val:
                return False
            if not checkNode(x.left,y.left) or not checkNode(x.right,y.right):
                return False
            return True
        
        return checkNode(p, q)
