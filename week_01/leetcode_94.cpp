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
    vector<int> inorderTraversal(TreeNode* root) {
        traversal(root);
        return rest;
    }

    void traversal(TreeNode *parent) {
        if (parent == nullptr) return;

        if (parent->left) traversal(parent->left);

        rest.push_back(parent->val);

        if (parent->right) traversal(parent->right);
    }

private:
    vector<int> rest;
};
