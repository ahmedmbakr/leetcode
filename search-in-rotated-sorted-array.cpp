//
// Created by bakr on 25/07/22.
//
//https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
using namespace std;

class Solution {
    int find_pivot(vector<int>& nums){
        int lbound = 0, rbound = nums.size() - 1;
        while(lbound <= rbound){
            int pivot_idx = ((lbound + rbound + 1) / 2);
            if(pivot_idx >= nums.size() || pivot_idx == 0)
                return 0;
            if(nums[pivot_idx] < nums[pivot_idx - 1])
                return pivot_idx;
            if(nums[rbound] < nums[pivot_idx]){
                lbound = pivot_idx + 1;
            }
            else{
                rbound = pivot_idx - 1;
            }
        }
        return 0;
    }

    int get_idx(vector<int> & nums, int lbound, int rbound, int target){
        while(lbound <= rbound){
            int idx = (lbound + rbound) / 2;
            if(idx < 0 || idx >= nums.size())
                return -1;
            if(nums[idx] == target)
                return idx;
            if(nums[idx] < target)
                lbound = idx + 1;
            else
                rbound = idx - 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1)
            return (nums[0] == target)? 0: -1;
        int pivot_idx = find_pivot(nums);
        int lbound, rbound;
        if(pivot_idx == 0 || (target >= nums[pivot_idx] && target < nums[0])){
            lbound = pivot_idx;
            rbound = nums.size() - 1;
        }
        else{
            lbound = 0;
            rbound = pivot_idx - 1;
        }
        return get_idx(nums, lbound, rbound, target);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 3};
    int target = 1;
    cout << sol.search(nums, target) << endl;
    return 0;
}
