//
// Created by bakr on 11/07/22.
//
//Problem Link: https://leetcode.com/problems/longest-palindromic-substring/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    string s;
    bool is_palindrome(int start_idx, int size){
        for(int i = 0;i < size / 2;++i){
            if(this->s[i + start_idx] != this->s[start_idx + size - i - 1])
                return false;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        this->s = s;
        for(int i = s.length(); i > 0; --i){
            for(int j = 0; j <= int(s.length()) - i; ++j) {
                if (is_palindrome(j, i))
                    return s.substr(j, i);
            }
        }
        return "" + s[0];
    }
};

int main(){
    Solution sol;
    cout << sol.longestPalindrome("cbbd") << endl;
    return 0;
}