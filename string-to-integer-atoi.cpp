//
// Created by bakr on 13/07/22.
//
//Problem Link: https://leetcode.com/problems/string-to-integer-atoi/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(i < s.length() && s[i] == ' '){
            ++i;
        }
        int sign = 1;
        if(s[i] == '+' || s[i] == '-'){
            sign = s[i] == '-'? -1: 1;
            ++i;
        }
        long ret = 0;
        while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
            ret *= 10;
            ret += s[i] - '0';
            ++i;
            if(ret > INT32_MAX){
                break;
            }
        }
        ret *= sign;
        if(ret > INT32_MAX){
            return INT32_MAX;
        }else if(ret < INT32_MIN){
            return INT32_MIN;
        }
        return (int)ret;
    }
};

int main(){
    Solution sol;
    cout << sol.myAtoi("4193 with words") << endl;
    return 0;
}