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
        if(!root){
            return {};
        }
        vector<int> order;
        order.reserve(100);

        travers(root, order);

        return order;
    }

private:
    void travers(TreeNode* root, vector<int>& order){
        if(root->left != nullptr){
            travers(root->left, order);
        }

        order.push_back(root->val);

        if(root->right != nullptr){
            travers(root->right, order);
        }
    }
};