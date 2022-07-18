//
// Created by bakr on 18/07/22.
//
//https://leetcode.com/problems/longest-common-prefix/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool ret = true;
        int i;
        for(i = 0; i < strs[0].length(); ++i){
            for(int j = 1; j < strs.size(); ++j){
                if(i >= strs[j].size() || strs[0][i] != strs[j][i])
                {
                    ret = false;
                    break;
                }
            }
            if(ret == false)break;
        }
        return i ==0? "": strs[0].substr(0, i);
    }
};

int main(){
    Solution sol;
    vector<string> vec = {"flower","flow","flight"};
    cout << sol.longestCommonPrefix(vec) << endl;
    return 0;
}

