#include <iostream>
#include <vector>

using namespace std;
//Problem Link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[i] + nums[j] == target){
                    return vector<int>{i, j};
                }
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
