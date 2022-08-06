//
// Created by bakr on 05/08/22.
//
//https://leetcode.com/problems/maximum-product-subarray/
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
public:
    int maxProduct(vector<int>& nums) {
        int prev_max = nums[nums.size() - 1], prev_min = nums[nums.size() - 1];
        int max_ret = prev_max;
        for(int i = nums.size() - 2; i >= 0; --i){
            int opt1 = nums[i] * prev_max;
            int opt2 = nums[i] * prev_min;
            prev_max = max(nums[i], max(opt1, opt2));
            prev_min = min(nums[i], min(opt1, opt2));

            max_ret = max(max_ret, prev_max);
        }
        return max_ret;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-2,3,-4};
//    vector<int> nums = {2,3,-2,4};
//    vector<int> nums = {-2,0,-1};
    cout << sol.maxProduct(nums);
    return 0;
}
