//
// Created by bakr on 12/07/22.
//
//Problem Link: https://leetcode.com/problems/reverse-integer/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
    int rev(int x){
        bool is_positive = x > 0;
        if(!is_positive){
            x = -x;
        }
        long ret_num = 0; // it was int, but I changed it to long because leetcode raises an exception when int numbers go out of boundaries
        while(x > 0){
            ret_num *= 10;
            ret_num += x % 10;
            x = x / 10;

        }
        if(!is_positive){
            ret_num= -ret_num;
        }
        return ret_num;
    }
public:
    int reverse(int x) {
        if(x == 0){
            return 0;
        }
        if(x == -pow(2, 31))
            return 0;
        while(x % 10 == 0){
            x /= 10;
        }
        int ret_val = rev(x);
        if(rev(ret_val) != x)
            return 0;
        return ret_val;
    }
};


int main(){
    Solution sol;
    cout << sol.reverse(123) << endl;
    return 0;
}
