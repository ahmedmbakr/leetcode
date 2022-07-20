//
// Created by bakr on 20/07/22.
//

//https://leetcode.com/problems/palindrome-linked-list/

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
    unsigned char arr[100000];
    int fill_arr_and_get_len(ListNode const * head){
        int len = 0;
        ListNode const * ptr = head;
        while(ptr != nullptr){
            arr[len] = ptr->val;
            ++len;
            ptr = ptr->next;
        }
        return len;
    }
public:
    bool isPalindrome(ListNode* head) {
        int len = fill_arr_and_get_len(head);
        int half = len / 2;
        for(int i = 0; i < half; ++i){
            if(arr[i] != arr[len - i - 1])
                return false;
        }
        return true;
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

int main(){
    Solution sol;
    vector<int> vec = {1, 2, 3, 2, 1};
    ListNode* head = create_list(vec);
    cout << sol.isPalindrome(head) << endl;
    return 0;
}
