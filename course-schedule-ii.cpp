//
// Created by bakr on 29/07/22.
//
//https://leetcode.com/problems/course-schedule-ii/

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
    vector<int> res;
    bool dfs(int course_id, vector<vector<int>>& vec, vector<bool>& visited, set<int>& req_set){
        if(visited[course_id])return true;
        visited[course_id] = true;
        for(auto req_course_id: vec[course_id]){
            int old_size = req_set.size();
            req_set.insert(req_course_id);
            if(old_size == req_set.size()) return false;
            if(!visited[req_course_id]){
                if(!dfs(req_course_id, vec, visited, req_set))
                    return false;
            }
            req_set.erase(req_course_id);
        }
        res.push_back(course_id);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> is_root_vec(numCourses, true);
        vector<bool> visited(numCourses, false);
        set<int> req_set;
        vector<vector<int>> vec(numCourses);
        for(auto temp : prerequisites){
            int course_id = temp[0];
            int req_course_id = temp[1];
            vec[course_id].push_back(req_course_id);
            is_root_vec[req_course_id] = false;
        }
        for(int i = 0; i < numCourses; ++i){
            if(is_root_vec[i]){
                if(!dfs(i, vec, visited, req_set))
                    return {};
            }
        }
        if(res.size() == numCourses)
            return res;
        return {};
    }
};

void print_vec(vector<int>& vec){
    for(int n: vec){
        cout << n << endl;
    }
}

int main(){
    Solution sol;
    vector<vector<int>> prerequisits = {{1, 0}};
    vector<int> res = sol.findOrder(2, prerequisits);
    print_vec(res);
}
