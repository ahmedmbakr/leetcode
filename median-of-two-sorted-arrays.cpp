//
// Created by bakr on 08/07/22.
//
//Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums2.size(); ++i){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        if(nums1.size() % 2 != 0){
            return nums1[nums1.size()/2];
        }
        else{
            return (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1]) / 2.0;
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums1{1,2};
    vector<int> nums2{3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
}
