//
// Created by bakr on 22/07/22.
//
//https://leetcode.com/problems/task-scheduler/
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
    static bool comp(int &x, int &y){
        return x > y;
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0)
            return tasks.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < tasks.size(); i++){
            if(mp.find(tasks[i]) == mp.end()){
                mp[tasks[i]] = 0;
            }
            mp[tasks[i]]++;
        }

        vector<int> vec;
        for(auto it = mp.begin(); it != mp.end(); it++){
            vec.push_back(it->second);
        }
        int res = 0;
        int stall;

        while(vec.size() > 0){
            sort(vec.begin(), vec.end(), comp);
            int len = min((int)vec.size(), n + 1);
            for(int i = len - 1; i >=0; --i){
                vec[i] --;
                if(vec[i] == 0){
                    vec.erase(vec.begin() + i);
                }
            }
            stall = n - (len - 1);
            res += len + stall;
        }
        return res - stall;
    }
};

int main(){
    Solution sol;
    vector<char> tasks = {'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E'};
    int n = 2;
    cout << sol.leastInterval(tasks, n) << endl;
    return 0;
}