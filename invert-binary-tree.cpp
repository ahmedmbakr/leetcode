//
// Created by bakr on 23/07/22.
//
//https://leetcode.com/problems/invert-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)return nullptr;

        auto left_temp = root->left;
        root->left = root->right;
        root->right = left_temp;

        if(root->left != nullptr){
            invertTree(root->left);
        }
        if(root->right != nullptr){
            invertTree(root->right);
        }
        return root;
    }
};

int main(){
    Solution sol;
    TreeNode child1(2), child2(3);
    TreeNode root(1, &child1, &child2);
    auto res = sol.invertTree(&root);
    return 0;
}