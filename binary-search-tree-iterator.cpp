//
// Created by bakr on 28/07/22.
//
//https://leetcode.com/problems/binary-search-tree-iterator/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    int arr[100000];
    int idx = 0;
    int length = 0;
    void dfs(TreeNode* node){
        if(node == nullptr) return;
        dfs(node->left);
        arr[length++] = node->val;
        dfs(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        length = 0;
        dfs(root);//fill arr
        idx = 0;
    }

    int next() {
        return arr[idx++];
    }

    bool hasNext() {
        return idx < length;
    }
};