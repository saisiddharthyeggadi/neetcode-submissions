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
/*
dfs ans, root
*/
    int dfs(int &ans, TreeNode* root){
        if(!root) return 0;

        int l = max(0, dfs(ans, root->left));
        int r = max(0, dfs(ans, root->right));

        ans = max(ans, root->val + l + r);

        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1000000;
        int a = dfs(ans, root);
        return ans;
    }
};
