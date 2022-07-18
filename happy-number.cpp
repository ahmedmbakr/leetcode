//
// Created by bakr on 18/07/22.
//
//https://leetcode.com/problems/happy-number/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> numbers;
        while(n != 1){
            int temp = n;
            n = 0;
            while(temp > 0){
                n += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            int previous_size = numbers.size();
            numbers.insert(n);
            if(numbers.size() == previous_size)// endless loop
                return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    cout << sol.isHappy(19) << endl;
    return 0;
}
