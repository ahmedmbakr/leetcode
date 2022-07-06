#include <iostream>
#include <vector>
#include <map>

using namespace std;
//Problem Link: https://leetcode.com/problems/two-sum/

class Solution {
    map<int, int> mp; //The key represents the number and the value is its index in the array
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i){
            mp[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); ++i){
            auto other_number_idx_it = mp.find(target - nums[i]);
            if(other_number_idx_it != mp.end() && other_number_idx_it->second != i){
                return vector<int>{i, mp[target - nums[i]]};
            }
        }
        return vector<int>{-1, -1};
    }
};

int main() {
    //std::cout << "Hello, World!" << std::endl;
    vector<int> vec{2,3,7};
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(vec, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
