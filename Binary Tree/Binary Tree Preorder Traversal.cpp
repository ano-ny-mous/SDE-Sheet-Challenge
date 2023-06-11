class Solution {
public:
    vector<int> res;
    void preorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }
};