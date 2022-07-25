//
// Created by bakr on 24/07/22.
//
//https://leetcode.com/problems/diameter-of-binary-tree/
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
    map<TreeNode*, TreeNode*> parentmp;
    map<TreeNode*, bool> visited;
    pair<int, TreeNode*> internal_dfs(TreeNode* node, int level){
        if(visited[node])return make_pair(level - 1, node);
        visited[node] = true;
        if((node->left == nullptr||visited[node->left]) && (node->right == nullptr || visited[node->right]) && (parentmp.find(node) == parentmp.end() || visited[parentmp[node]])){
            return make_pair(level, node);
        }
        pair<int, TreeNode*> l, r, p;
        int llevel = 0, rlevel = 0, plevel = 0;
        if(node->left != nullptr && !visited[node->left]) {
            if(parentmp.find(node->left) == parentmp.end())
                parentmp[node->left] = node;
            l = internal_dfs(node->left, level + 1);
            llevel = l.first;
        }
        if(node->right != nullptr && !visited[node->right]){
            if(parentmp.find(node->right) == parentmp.end())
                parentmp[node->right] = node;
            r = internal_dfs(node->right, level + 1);
            rlevel = r.first;
        }
        if(parentmp.find(node) != parentmp.end() && !visited[parentmp[node]]){
            p = internal_dfs(parentmp[node], level + 1);
            plevel = p.first;
        }
        if(llevel >= rlevel && llevel >= plevel){
            return l;
        }
        else if(rlevel >= llevel && rlevel >= plevel){
            return r;
        }
        return p;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        auto ret_node = internal_dfs(root, 0);
        for(auto it = visited.begin(); it != visited.end(); it++)
            it->second = false;
        auto ret_node2 = internal_dfs(ret_node.second, 0);
        return ret_node2.first;
    }
};


int main(){
    Solution sol;
//    TreeNode node(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    TreeNode node(1, new TreeNode(2), nullptr);
    cout << sol.diameterOfBinaryTree(&node) << endl;
    return 0;
}