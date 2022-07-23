//
// Created by bakr on 22/07/22.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ret = 0;
        unordered_map<string, pair<int, int>> mp;//the first of the pair is number of strings which cannot find any matching closing strings
        for(int i = 0; i < words.size(); ++i){
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            if(mp.find(rev) != mp.end()){
                if(rev[0] == rev[1]){
                    if(mp[rev].first > mp[rev].second)mp[rev].second++;
                    else mp[rev].first++;
                }
                else
                    mp[rev].second++;
            }
            else if(mp.find(words[i]) != mp.end()){
                mp[words[i]].first++;

            }
            else{
                mp[words[i]] = make_pair(1, 0);
            }
        }
        bool increment_2_allowed = false;
        for(auto it = mp.begin(); it != mp.end(); it++){
            auto pr = it->second;
            ret += min(pr.first, pr.second) * 4;
            if(pr.first != pr.second && it->first[0] == it->first[1]){
                increment_2_allowed = true;
            }
        }
        if(increment_2_allowed)
            return ret + 2;
        return ret;
    }
};

int main(){
    vector<string> words = {"dd","aa","bb","dd","aa","dd","bb","dd","aa","cc","bb","cc","dd","cc"};
    Solution sol;
    cout << sol.longestPalindrome(words) << endl;
    return 0;
}