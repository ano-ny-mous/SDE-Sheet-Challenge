class Solution {
public:
    vector<int> res;
    void postorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
	res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return res;
    }
};