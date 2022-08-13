//
// Created by bakr on 13/08/22.
//
//https://leetcode.com/problems/3sum-closest/

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

/*
 * Input: nums = [-1,2,1,-4], target = 1
Output: 2

 Input: nums = [0,0,0], target = 1
Output: 0
 */

class Solution {
    int find_in_arr(int key, vector<int>& nums){
        int left = 0, right = nums.size() - 1;
        int idx = -1;
        while(left <= right){
            idx = (left + right) / 2;
            if(key == nums[idx])
                return idx;
            if(key > nums[idx])
                left = idx + 1;
            if(key < nums[idx])
                right = idx - 1;
        }
        return idx;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int retMin = nums[0] + nums[1] + nums[2], retMinDiff = 1e9;

        for(int i = 0;i < nums.size(); ++i){
            int newTarget = target - nums[i];
            for(int j = i + 1; j < nums.size(); ++j){
//                if(nums[j] > newTarget)
//                    break;
                int finalTarget = newTarget - nums[j];
                int found_idx = find_in_arr(finalTarget, nums);
                int ret = nums[i] + nums[j];
                if(found_idx != i && found_idx != j && ret + nums[found_idx] == target)
                    return ret + nums[found_idx];

                int inds[] = {-1, 0, 1};
                for(int k = 0; k < 3; k++){
                    int idx = found_idx + k;
                    if(idx != i && idx != j && idx >= 0 && idx < nums.size() && abs(ret + nums[idx] - target) < retMinDiff)
                        retMinDiff =  abs(ret + nums[idx] - target), retMin = ret + nums[idx];
                }
                if(finalTarget < retMin)
                    break;
            }
        }
        return retMin;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    //-4, -1, 1, 2
//    vector<int> nums = {0, 1, 2};
    int target = 1;
    cout << sol.threeSumClosest(nums, target) << endl;
    return 0;
}


