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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*, int>> q;
        vector<int> ans;
        int curr_level = 0;
        q.push(make_pair(root, 1));
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int level = q.front().second;
            if(curr_level != level) {
                ans.push_back(curr->val);
                curr_level++;
            }
            if(curr->right) q.push(make_pair(curr->right, level+1));
            if(curr->left) q.push(make_pair(curr->left, level+1));
            q.pop();
        }
        return ans;
    }
};
