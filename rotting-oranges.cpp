//
// Created by bakr on 28/07/22.
//
//https://leetcode.com/problems/rotting-oranges/
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
    int is[4] = {1, -1, 0, 0};
    int js[4] = {0, 0, 1, -1};

    struct qElem{
        int i;
        int j;
        int minute;
        qElem(int i, int j, int minute){
            this->i = i;
            this->j = j;
            this->minute = minute;
        }
    };
    queue<qElem> q;
    bool all_rotten(vector<vector<int>>& grid){
        for(int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1)return false;
            }
        }
        return true;
    }
    int minute;
    int bfs(vector<vector<int>>& grid){
        if(all_rotten(grid))return 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(all_rotten(grid))return minute;
            int i = p.i, j = p.j;
            for(int k = 0;k < 4; k++){
                int newi = i + is[k];
                int newj = j + js[k];
                if(newi < 0 || newi >= grid.size() || newj < 0 || newj >= grid[0].size() || grid[newi][newj] != 1)continue;
                grid[newi][newj] = 2;
                q.push({newi, newj, p.minute + 1});
                minute = max(minute, p.minute + 1);
            }
        }
        return -1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0;j < grid[0].size(); ++j){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                }
            }
        }

        return bfs(grid);
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,1},{0,1,2}};
    cout << sol.orangesRotting(grid) << endl;
    return 0;
}