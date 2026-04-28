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
/*
there are 2 different problems at hand here , one is to serialize and other is to 
deserialize. So for seria
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        if(root->left == nullptr && root->right==nullptr){
            return to_string(root->val) + " N N";
        }

        string res = to_string(root->val) + " ";
        if(root->left) res += serialize(root->left) + " ";
        else res += "N ";
        if(root->right) res += serialize(root->right);
        else res += "N ";

        return res;
    }
    //1 2 N N 3 4 N N 5 N N
    /*
    if root is not null , TreeNode* temp = new TreeNode(root->val)
    if root->left and root->right are N then this is the last node , then return temp
    or we need to create temp left and temp right 
    if root left is true then 
    root = v[0];
    root->left = v[1];
    root->right =  
    */
    // Decodes your encoded data to tree.
    TreeNode* create(vector<string> &v, int &i){
        if(i>=v.size() || v[i] == "N") {
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
        stringstream temp(data);
        string number;
        vector<string> v;
        while(temp >> number){
            v.push_back(number);
        }
        int i = 0;
        return create(v, i);
    }
};
