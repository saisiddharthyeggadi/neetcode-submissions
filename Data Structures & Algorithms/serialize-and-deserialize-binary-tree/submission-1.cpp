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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        if(root->left == nullptr && root->right == nullptr) 
            return to_string(root->val)+" N N";
        
        string res = to_string(root->val)+" ";
        if(root->left) res += serialize(root->left)+" ";
        else res += "N ";
        if(root->right) res += serialize(root->right)+" ";
        else res += "N ";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* create(vector<string> &v, int &i){
        if(i >= v.size() || v[i]=="N") {
            i++;
            return nullptr;
        }
        TreeNode* curr = new TreeNode(stoi(v[i]));
        i++;
        
        curr->left = create(v, i);
        curr->right = create(v, i);
        return curr;
    }
    TreeNode* deserialize(string data) {

        stringstream ss(data);
        vector<string>v;
        string number;
        while(ss >> number){
            v.push_back(number);
        }
        int i=0;
        return create(v, i);
    }
};
