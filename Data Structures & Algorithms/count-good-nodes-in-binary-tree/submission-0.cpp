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
    void depth(TreeNode* root, int top, int &res){
        if(!root) return;
        if(root->val >= top){
            res++;
            top = root->val;
        }
        depth(root->left, top, res);
        depth(root->right, top, res);

    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        depth(root, -101, ans);
        return ans;
    }
};
