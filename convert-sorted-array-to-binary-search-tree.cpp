//
// Created by bakr on 27/07/22.
//
//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* dfs(vector<int>& nums, int lbound, int rbound){
        if(rbound < lbound) return nullptr;
        if(lbound == rbound) return new TreeNode(nums[lbound]);
        int mid = (lbound + rbound) / 2;
        TreeNode* left_node = dfs(nums, lbound, mid - 1);
        TreeNode* right_node = dfs(nums, mid + 1, rbound);
        return new TreeNode(nums[mid], left_node, right_node);
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = dfs(nums, 0, nums.size() - 1);
        return root;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* root = sol.sortedArrayToBST(nums);
    return 0;
}