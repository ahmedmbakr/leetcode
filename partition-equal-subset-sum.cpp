//
// Created by bakr on 03/08/22.
//
//https://leetcode.com/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
    int ks[20001][200];
    int target;
    bool dfs(int idx, int sum, vector<int>& nums){
        if(idx == -1)
            return sum == target;
        if(sum > target)
            return false;
        if(ks[sum][idx] != -1)
            return ks[sum][idx];
        bool option1 = dfs(idx - 1, sum + nums[idx], nums);//take
        bool option2 = dfs(idx - 1, sum, nums); //leave
        return ks[sum][idx] = (option1 || option2);
    }
public:
    bool canPartition(vector<int>& nums) {
        memset(ks, -1, sizeof ks);
        if(nums.size() == 1)
            return false;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }

        if(sum % 2 != 0)
            return false;
        target = sum / 2;
        if(dfs(nums.size() - 1, 0, nums))
            return true;
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {28,4,26,1,36,42,10,32,27};
    cout << sol.canPartition(nums) << endl;
    return 0;
}