//
// Created by bakr on 24/07/22.
//
//https://leetcode.com/problems/path-sum-iii/
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
    int target_sum;
    int dfs(TreeNode* node, long curr_sum){
        int ret_cnt = 0;
        if(curr_sum + node->val == (long)target_sum){
            ret_cnt++;
        }
        if(node->left != nullptr){
            ret_cnt += dfs(node->left, curr_sum + node->val);
        }
        if(node->right != nullptr){
            ret_cnt += dfs(node->right, curr_sum + node->val);
        }
        return ret_cnt;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)return 0;
        int ret = 0;
        this->target_sum = targetSum;
        ret += dfs(root, 0);
        if(root->left != nullptr){
            ret += pathSum(root->left, targetSum);
        }
        if(root->right != nullptr){
            ret += pathSum(root->right, targetSum);
        }
        return ret;
    }
};

int main(){
    Solution sol;
    TreeNode node(10, new TreeNode(5, new TreeNode(3, new TreeNode(3), new TreeNode(-2)), new TreeNode(2, new TreeNode(1),
                                                                                                       nullptr)), new TreeNode(-3, new TreeNode(11),
                                                                                                                               nullptr));
    cout << sol.pathSum(&node, 8) <<endl;
    return 0;
}
