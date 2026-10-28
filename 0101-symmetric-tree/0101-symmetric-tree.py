# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        def checkCounterpart(p,q):
            if (not p and q) or (p and not q):
                return False

            if not p:
                return True

            if p.val != q.val:
                return False

            return checkCounterpart(p.right,q.left) and checkCounterpart(p.left,q.right)

        return checkCounterpart(root.right,root.left)
                