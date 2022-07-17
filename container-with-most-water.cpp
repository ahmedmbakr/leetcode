//
// Created by bakr on 16/07/22.
//
//Problem Link: https://leetcode.com/problems/container-with-most-water/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& vec) {
        int lidx = 0, ridx = vec.size() - 1;
        int max_area = (ridx - lidx) * min(vec[ridx], vec[lidx]);
        for(int i = 0 ; i < vec.size() && ridx > lidx; ++i){
            int area = (ridx - (lidx)) * min(vec[lidx], vec[ridx]);
            if(area > max_area){
                max_area = area;
            }
            if(vec[lidx] > vec[ridx])
                ridx--;
            else
                lidx++;
        }
        //cout << lidx << " " << ridx << endl;
        return max_area;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {2,3,4,5,18,17,6};
    cout << sol.maxArea(vec);
    return 0;
}