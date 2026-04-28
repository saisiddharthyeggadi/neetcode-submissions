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
//recursion
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* head = new TreeNode(preorder[0]);

        if(preorder.size() == 1) return head;

        int center = -1;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == preorder[0]){
                center = i;
                break;
            }
        }

        vector<int> left_pre(preorder.begin()+1, preorder.begin()+1+center);
        vector<int> right_pre(preorder.begin()+1+center, preorder.end());

        vector<int> left_in(inorder.begin(), inorder.begin()+center);
        vector<int> right_in(inorder.begin()+center+1, inorder.end());

        if(center > 0)
            head->left = buildTree(left_pre, left_in);

        if(right_in.size() > 0)
            head->right = buildTree(right_pre, right_in);

        return head;
    }
};
