/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Account for empty tree
        if (root == NULL)
            return true;
        
        // Use smallest and largest int values to start to account for root node
        return is_valid_BST_helper(root, INT_MIN, INT_MAX);
    }
    
    bool is_valid_BST_helper(TreeNode* root, long min, long max)
    {        
        // Reached a leaf node
        if (root == NULL)
            return true;
        
        // If it breaks the rules
        if (root->val < min || root->val > max)
            return false;
        
        // Otherwise, recurse by visiting both children
        // Here we do not want to allow equal values so we subtract and add 1 respectively
        if (!is_valid_BST_helper(root->left, min, (long) root->val - 1) ||
                !is_valid_BST_helper(root->right, (long) root->val + 1, max))
            return false;
            
        // Catch-all
        return true;
    }
};
