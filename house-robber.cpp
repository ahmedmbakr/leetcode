//
// Created by bakr on 01/08/22.
//
//https://leetcode.com/problems/house-robber/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#include <queue>
using namespace std;

class Solution {
    int dfs(int idx, vector<int> &nums, vector<int> &dp){
        if(idx >= nums.size()){
            return 0;
        }
        if(idx >= nums.size() - 2){
            dp[idx] = nums[idx];
            return dp[idx];
        }
        if(dp[idx] != -1)
            return dp[idx];
        int cand1 = dfs(idx + 2, nums, dp);
        int cand2 = dfs(idx + 3, nums, dp);
        dp[idx] = nums[idx] + max(cand1, cand2);
        return dp[idx];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int val1 = dfs(0, nums, dp);
        int val2 = dfs(1, nums, dp);
        return max(val1,  val2);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 9, 3, 1, 8};
//    vector<int> nums = {1,2,3,1};
    cout << sol.rob(nums);
    return 0;
}