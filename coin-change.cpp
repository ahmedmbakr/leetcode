//
// Created by bakr on 01/08/22.
//
//https://leetcode.com/problems/coin-change/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#include <queue>
using namespace std;

class Solution {
    struct QueueElem{
        int amount;
        int num_coins;
    };
    bool visited[10001];
    queue<QueueElem> q;
    int add_children_for_amount(int amount, vector<int> &coins, int num_coins){
        if(visited[amount])
            return -1;
        visited[amount] = true;
        QueueElem queueElem;
        queueElem.num_coins = num_coins + 1;
        for(int i = 0; i < coins.size(); ++i){
            queueElem.amount = amount - coins[i];
            if(queueElem.amount == 0)
                return queueElem.num_coins;
            if(queueElem.amount < 0 || visited[queueElem.amount])
                continue;
            q.push(queueElem);
        }
        return -1;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int num_coins = add_children_for_amount(amount, coins, 0);
        if(num_coins >= 0)return num_coins;

        while(!q.empty()){
            QueueElem queueElem;
            queueElem = q.front();
            q.pop();

            int num_coins = add_children_for_amount(queueElem.amount, coins, queueElem.num_coins);
            if(num_coins >= 0)
                return num_coins;
        }
        return -1;
    }
};

int main(){
    Solution sol;

    vector<int> coins = {186,419,83,408};
//    vector<int> coins = {1, 200};
    int amount = 6249;
//int amount = 2;
    cout << sol.coinChange(coins, amount);
    return 0;
}