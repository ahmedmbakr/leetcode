//
// Created by bakr on 19/07/22.
//
//https://leetcode.com/problems/multiply-strings/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
using namespace std;

class Solution {
    string internal_mul(int digit, string num){// digit is a number from 0 to 9
        if(digit == 0){
            return "0";
        }else if(digit == 1){
            return num;
        }
        string res = "";
        int carry = 0;
        for(int i = num.length() - 1; i >= 0; --i){
            int another_digit = num[i] - '0';
            int int_res = digit * another_digit + carry;
            if(i == 0){
                res = to_string(int_res) + res;
            }else{
                res = to_string(int_res % 10) + res;
                carry = int_res / 10;
            }
        }
        return res;
    }
    string internal_add(string num1, string num2){
        if(num2.length() < num1.length()){
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }
        int carry = 0;
        string res_str = "";
        int num1_idx = num1.length() - 1;
        for(int i = num2.length() - 1; i >= 0; --i){
            int d1 = num1_idx < num1.length()? num1[num1_idx--] - '0': 0;
            int d2 = num2[i] - '0';
            int res =d1 + d2 + carry;
            if(i == 0){
                res_str = to_string(res) + res_str;
            }else{
                res_str = to_string(res % 10) + res_str;
                carry = res / 10;
            }
        }
        return res_str;
    }
public:
    string multiply(string num1, string num2) {
        string acc_res = "0";
        if(num1 == "0" || num2 == "0")
            return "0";
        for(int i = num2.length() - 1; i >= 0; --i){
            string res = internal_mul(num2[i] - '0', num1);
            int j = num2.length() - i - 1;
            while(j--){
                res += "0";
            }
            acc_res = internal_add(acc_res, res);
        }
        return acc_res;
    }
};

int main(){
    Solution sol;
    cout << sol.multiply("123", "456") << endl;
    return 0;
}