//
// Created by bakr on 08/07/22.
//

//Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int max_seq_length = 0, curr_seq_start_idx = 0;
        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            if(mp.find(c) != mp.end()){
                if(mp[c] >= curr_seq_start_idx){//conflict
                    max_seq_length =  (i - curr_seq_start_idx) > max_seq_length? (i - curr_seq_start_idx): max_seq_length;
                    curr_seq_start_idx = mp[c] + 1;
                }
            }
            mp[c] = i;
        }
        max_seq_length =  (s.length() - curr_seq_start_idx) > max_seq_length? (s.length() - curr_seq_start_idx): max_seq_length;
        return max_seq_length;
    }
};

int main(){
    string s = "abcdaaqnbcomnlo";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
