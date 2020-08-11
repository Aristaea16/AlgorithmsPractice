/*
 * Laurie Kirk 8-10-20
 * Finding the lowest common ancestor (LCA) of a Binary Search Tree (BST)
 * Time complexity: O(lgn) for balanced BST, but O(n) for unbalanced
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // See if we can move down an ancestor on the left or right
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        
        // Otherwise, we are at the lowest common ancestor
        return root;
    }
};
