//
// Created by bakr on 20/07/22.
//
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    int get_list_length(ListNode* head){
        int len = 0;
        ListNode * ptr = head;
        while(ptr != nullptr){
            ++len;
            ptr = ptr->next;
        }
        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = get_list_length(head);
        n = len - n;
        if(n == 0){
            return head->next;
        }
        ListNode * ptr = head;
        int idx = 0;
        while(ptr != nullptr){
            if(idx == n - 1){
                if(n != len - 1)
                    ptr->next = ptr->next->next;
                else
                    ptr->next = nullptr;
                return head;
            }
            ptr = ptr->next;
            idx++;
        }
        return nullptr; // will never be reached
    }
};

ListNode* create_list(vector<int>& vec){
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
    vector<int> vec = {1, 2, 3, 4, 5};
    ListNode* head = create_list(vec);
    ListNode* ret_head = sol.removeNthFromEnd(head, 1);
    print_linked_list(ret_head);
    return 0;
}
