//
// Created by bakr on 25/07/22.
//
//https://leetcode.com/problems/search-a-2d-matrix/

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
    int target;
    bool binary_search(vector<vector<int>>& matrix, int lbound, int rbound){
        if(lbound < 0 || rbound >= matrix.size() * matrix[0].size() || rbound < lbound)
            return false;
        int flat_idx = (lbound + rbound) / 2;
        int i = flat_idx / matrix[0].size();
        int j = flat_idx % matrix[0].size();
        if(target == matrix[i][j])
            return true;
        if(matrix[i][j] < target){
            return binary_search(matrix, flat_idx + 1, rbound);
        }
        else{
            return binary_search(matrix, lbound, flat_idx - 1);
        }
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        this->target = target;
        return binary_search(matrix, 0, matrix.size() * matrix[0].size() - 1);
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 7;
    cout << sol.searchMatrix(matrix, target);
    return 0;
}