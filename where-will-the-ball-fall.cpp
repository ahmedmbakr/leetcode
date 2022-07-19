//
// Created by bakr on 19/07/22.
//

//https://leetcode.com/problems/where-will-the-ball-fall/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
using namespace std;

class Solution {
    int get_final_column_id(int init_row, int init_col, vector<vector<int>>& grid){
        int row = init_row, col = init_col;
        int is_ball_up_line = 1;//1 if up the line and 0 otherwise. We always start with the ball up the line
        while(true){
            if(row == grid.size() - 1 && !is_ball_up_line){
                return col;
            }
            if(grid[row][col] == 1){
                if(is_ball_up_line && (col == grid[0].size() - 1 || grid[row][col + 1] == -1)){
                    return -1;
                }
                if(is_ball_up_line){
                    col += 1;
                }
                else{
                    row += 1;
                }
            }
            else if(grid[row][col] == -1){
                if(is_ball_up_line && (col == 0 || grid[row][col - 1] == 1)){
                    return -1;
                }
                if(is_ball_up_line){
                    col -= 1;
                }
                else{
                    row += 1;
                }
            }
            if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
                return -1;

            is_ball_up_line = (is_ball_up_line + 1) % 2;
        }
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ret_vec;
        for(int i = 0; i < grid[0].size(); ++i){
            ret_vec.push_back(get_final_column_id(0, i, grid));
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
    vector<vector<int>> grid = {{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}};
    auto ret_vec = sol.findBall(grid);
    sol.print_mat(ret_vec);
    return 0;
}