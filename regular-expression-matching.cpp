//
// Created by bakr on 15/07/22.
//
//Problem Link: https://leetcode.com/problems/regular-expression-matching/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        //cout << p << endl;
        int s_idx = 0, p_idx = 0;
        while(s_idx < s.length() || p_idx < p.length()){
            if((p[p_idx] == '.' || (p[p_idx] >= 'a' && p[p_idx] <= 'z')) && (p_idx == p.length() - 1 || p[p_idx + 1] != '*')){
                if((p[p_idx] != '.' && p[p_idx] != s[s_idx]) || s_idx >= s.length())
                    return false;
                p_idx += 1;
                s_idx += 1;
            }
            else if(p_idx < p.length() && p[p_idx + 1] == '*'){
                if(isMatch(s.substr(s_idx, s.length() - s_idx), p.substr(p_idx + 2, p.length() - p_idx - 2)))
                    return true;
                while(s_idx < s.length() && (p[p_idx] == '.' || s[s_idx] == p[p_idx])){
                    if(isMatch(s.substr(s_idx + 1, s.length() - s_idx - 1), p.substr(p_idx + 2, p.length() - p_idx - 2)))
                        return true;
                    s_idx += 1;
                }

                p_idx += 2;
            } else{
                return false;
            }

        }
        return s_idx == s.length() && p_idx == p.length();
    }
};

int main(){
    Solution sol;
    cout << sol.isMatch("a", ".*..a*");
    return 0;
}