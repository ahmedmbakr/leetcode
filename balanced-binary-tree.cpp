//
// Created by bakr on 23/07/22.
//
//https://leetcode.com/problems/balanced-binary-tree/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int traverse_node(TreeNode* node, int level){
        int score, lscore = level, rscore = level;
        if(node->left == nullptr && node->right == nullptr)
            return level;
        if(node->left != nullptr){
            lscore = traverse_node(node->left, level + 1);
        }
        if(node->right != nullptr){
            rscore = traverse_node(node->right, level + 1);
        }
        if(lscore == -1 || rscore == -1)
            return -1;

        if(abs(lscore - rscore) > 1)
            return -1;
        else
            return max(lscore, rscore);

        if(node->left != nullptr)
            return lscore;
        return rscore;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)return true;
        if(traverse_node(root, 0) == -1)
            return false;
        return true;
    }
};

int main(){
    TreeNode root(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    Solution sol;
    cout << sol.isBalanced(&root) << endl;
    return 0;
}


