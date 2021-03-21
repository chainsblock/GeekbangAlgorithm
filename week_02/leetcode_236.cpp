/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        search(root, p, q);
        return rest;
    }

    bool search(TreeNode *node, TreeNode *p, TreeNode *q) {

        if (node == nullptr) return false;

        bool node_is = node == p || node == q;

        bool r_found = false, l_found = false;

        if (node->left) {
            l_found = search(node->left, p, q);
        }

        if (node_is && l_found) {
            rest = node;
            return true;
        }

        if (node->right) {
            r_found = search(node->right, p, q);
        }

        if (node_is && r_found) {
            rest = node;
            return true;
        }

        if (l_found && r_found) {
            rest = node;
            return true;
        }

        if (node == p || node == q || l_found || r_found) return true;
        return false;
    }

private:
    TreeNode *rest = nullptr;
};