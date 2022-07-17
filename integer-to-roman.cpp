//
// Created by bakr on 17/07/22.
//
//Problem Link: https://leetcode.com/problems/integer-to-roman/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string nums = to_string(num);
        string ret = "";
        for(int i = 0; i < nums.length(); ++i){
            if(nums.length() - i == 4){
                int temp = nums[i] - '0';
                while(temp--){
                    ret += "M";
                }
            }
            else if(nums.length() - i == 3){
                if(nums[i] == '9'){
                    ret += "CM";
                }
                else if(nums[i] >= '5'){
                    int temp = nums[i] - '5';
                    ret += "D";
                    while(temp --){
                        ret += "C";
                    }
                }
                else{
                    if(nums[i] == '4'){
                        ret += "CD";
                    }
                    else{
                        int temp = nums[i] - '0';
                        while(temp--){
                            ret += "C";
                        }
                    }
                }
            }
            else if(nums.length() - i == 2){
                if(nums[i] == '9'){
                    ret += "XC";
                }
                else if(nums[i] >= '5'){
                    int temp = nums[i] - '5';
                    ret += "L";
                    while(temp--){
                        ret += "X";
                    }
                }
                else{
                    if(nums[i] == '4'){
                        ret += "XL";
                    }
                    else{
                        int temp = nums[i] - '0';
                        while(temp--){
                            ret += "X";
                        }
                    }
                }
            }
            else{
                if(nums[i] == '9'){
                    ret += "IX";
                }
                else if(nums[i] >= '5'){
                    ret+= "V";
                    int temp = nums[i] - '5';
                    while(temp--){
                        ret+= "I";
                    }
                }
                else{
                    if(nums[i] == '4'){
                        ret += "IV";
                    }
                    else{
                        int temp = nums[i] - '0';
                        while(temp--){
                            ret += "I";
                        }
                    }
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution sol;
    cout << sol.intToRoman(1994) << endl;
    return 0;
}