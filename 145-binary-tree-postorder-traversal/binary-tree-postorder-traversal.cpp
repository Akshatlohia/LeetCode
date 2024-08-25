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
    void postOrderTrav(TreeNode * curr, vector < int > & preOrder) {
        if (curr == NULL)
            return;

        postOrderTrav(curr -> left, preOrder);
        postOrderTrav(curr -> right, preOrder);
        preOrder.push_back(curr -> val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector < int > preOrder;
        postOrderTrav(root, preOrder);
        return preOrder;
    }
};