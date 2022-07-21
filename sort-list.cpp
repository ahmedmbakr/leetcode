//
// Created by bakr on 21/07/22.
//
//https://leetcode.com/problems/sort-list/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    vector<int> convert_to_vec(ListNode* head){
        ListNode* ptr = head;
        vector<int> retvec;
        while(ptr != nullptr){
            retvec.push_back(ptr->val);
            ptr = ptr->next;
        }
        return retvec;
    }

    ListNode* create_list(vector<int>& vec){
        if(vec.size() == 0)return nullptr;
        ListNode* head = new ListNode(vec[0]);
        ListNode* ptr = head;
        for(int i = 1; i < vec.size(); ++i){
            ptr->next = new ListNode(vec[i]);
            ptr = ptr->next;
        }
        return head;
    }

public:
    ListNode* sortList(ListNode* head) {
        auto vec = convert_to_vec(head);
        sort(vec.begin(), vec.end());
        ListNode* retnode = create_list(vec);
        return retnode;
    }
};

int main(){
    Solution sol;

    return 0;
}



