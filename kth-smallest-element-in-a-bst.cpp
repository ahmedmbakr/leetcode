//
// Created by bakr on 28/07/22.
//
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int k;
    int res = -1;
    int dfs(TreeNode* node, int next_cnt){
        if(res >= 0) { return next_cnt; }
        if(node->left == nullptr && node->right == nullptr){
            if(k == next_cnt){
                res = node->val;
                return next_cnt;
            }
            return next_cnt + 1;
        }
        if(node->left != nullptr){
            next_cnt = dfs(node->left, next_cnt);
            if(res >= 0) { return next_cnt; }
        }
        if(k == next_cnt){
            res = node->val;
            return next_cnt;
        }
        if(node->right != nullptr){
            next_cnt = dfs(node->right, next_cnt + 1);
            if(res >= 0) { return next_cnt; }
            return next_cnt;
        }
        return next_cnt + 1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        dfs(root, 1);
        return res;
    }
};

int main(){
    Solution sol;
//    TreeNode root(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(6));
    TreeNode root(1, new TreeNode(0), new TreeNode(2));
    cout << sol.kthSmallest(&root, 2) << endl;

    return 0;
}