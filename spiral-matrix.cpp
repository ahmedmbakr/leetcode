//
// Created by bakr on 18/07/22.
//
//https://leetcode.com/problems/spiral-matrix/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
using namespace std;

class Solution {
    int inc_arr[4][2] = {{0,  1}, // 'r'
                         {1,  0}, // 'd'
                         {0,  -1},// 'l;
                         {-1, 0}  // 'u'
                        };
    int direction = 0;// can take one of the values
    pair<int, int> get_next_idx(vector<vector<bool>>& visited, int row, int col, int level = 0){
        int next_r = row + inc_arr[this->direction][0], next_c = col + inc_arr[this->direction][1];
        if(next_r >= 0 && next_r < visited.size() && next_c >= 0 && next_c < visited[0].size() && !visited[next_r][next_c]){
            visited[next_r][next_c] = true;
            return make_pair(next_r, next_c);
        }else if(level == 0){
            this->direction = (this->direction + 1) % 4;
            return this->get_next_idx(visited, row, col, 1);
        }

        return make_pair<int, int>(-1, -1);// cannot find a feasible location
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret_vec = {matrix[0][0]};
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        int row = 0, col = 0;
        visited[0][0] = true;
        while(row >= 0 && col >= 0){
            auto ret_pair = this->get_next_idx(visited, row, col);
            if(ret_pair.first == -1)break;
            row = ret_pair.first;
            col = ret_pair.second;
            ret_vec.push_back(matrix[row][col]);
        }
        return ret_vec;
    }

    void print_mat(vector<int>& matrix){
        cout << "[";
        for(int i = 0; i < matrix.size() - 1; ++i){
            cout << matrix[i]<<',';
        }
        cout << matrix[matrix.size() - 1] << "]" << endl;
    }
};

int main(){
    Solution sol;
    vector<vector<int>>matrix = {{1,2,3},{4,5,6},{7,8,9}};
    auto ret_mat = sol.spiralOrder(matrix);
//    vector<int> ret_mat = {1,2,3};
    sol.print_mat(ret_mat);
    return 0;
}
