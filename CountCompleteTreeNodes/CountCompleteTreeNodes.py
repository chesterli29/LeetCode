# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        l = getLeft(root)
        r = getRight(root)
        if l == r:
            return (2 << l) - 1
        else:
            return self.countNodes(root.left) + self.countNodes(root.right) + 1

def getLeft(root):
    count = 0
    while root.left is not None:
        count += 1
        root = root.left
    return count

def getRight(root):
    count = 0
    while root.right is not None:
        count += 1
        root = root.right
    return count