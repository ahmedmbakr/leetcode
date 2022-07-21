//
// Created by bakr on 21/07/22.
//
//https://leetcode.com/problems/odd-even-linked-list/
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
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* odd_head = nullptr, *even_head = nullptr, *o_ptr = nullptr, *e_ptr = nullptr;
        ListNode* ptr = head;
        int idx = 0;
        while(ptr != nullptr){
            idx++;
            if(idx % 2 == 0){
                if(even_head == nullptr){
                    even_head = e_ptr = ptr;
                }else{
                    e_ptr->next = ptr;
                    e_ptr = ptr;
                }
            }
            else{
                if(odd_head == nullptr){
                    odd_head = o_ptr = ptr;
                }else{
                    o_ptr->next = ptr;
                    o_ptr = ptr;
                }
            }
            ptr = ptr->next;
        }
        if(e_ptr != nullptr)
            e_ptr->next = nullptr;
        if(o_ptr != nullptr)
            o_ptr->next = even_head;
        return odd_head;
    }
};

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

void print_linked_list(ListNode* head){
    ListNode* ptr = head;
    while(ptr != nullptr){
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main(){
    Solution sol;
    vector<int> vec;
    auto head = create_list(vec);
    auto res_head = sol.oddEvenList(head);
    print_linked_list(res_head);
    return 0;
}
