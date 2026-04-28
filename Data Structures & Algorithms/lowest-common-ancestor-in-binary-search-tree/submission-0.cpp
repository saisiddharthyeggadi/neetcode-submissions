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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = p->val;
        int b = q->val;
        TreeNode* cur = root;

        while (cur) {
            // If both p and q are less than cur, LCA is in left subtree
            if (a < cur->val && b < cur->val) {
                cur = cur->left;
            }
            // If both are greater, LCA is in right subtree
            else if (a > cur->val && b > cur->val) {
                cur = cur->right;
            }
            // Otherwise cur is the split point (one in left, one in right, or one is cur)
            else {
                return cur;
            }
        }
        return nullptr; // should not happen if p and q are guaranteed to exist
    }
};
