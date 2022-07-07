//
// Created by bakr on 07/07/22.
//
//Problem Link: https://leetcode.com/problems/add-two-numbers/
#include <iostream>
#include <vector>
#include <map>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0;
        int num2 = 0;
        int carry = 0;
        int res;
        ListNode* result = new ListNode();
        ListNode* result_ptr = result;
        int counter = 0;
        while(l1 != nullptr or l2 != nullptr){
            num1 = (l1 != nullptr)? l1->val: 0;
            num2 = (l2 != nullptr)? l2->val: 0;
            res = num1 + num2 + carry;
            carry = res / 10;
            res = res % 10;
            if(counter == 0){
                ++counter;
                result_ptr->val = res;
            }
            else{
                result_ptr->next = new ListNode(res);
                result_ptr = result_ptr->next;
            }
            l1 = (l1 != nullptr)? l1->next: nullptr;
            l2 = (l2 != nullptr)? l2->next: nullptr;
        }
        if(carry != 0){
            result_ptr->next = new ListNode(carry);
        }
        return result;
    }
};

void print_list_node(ListNode* list_node){
    while(list_node != nullptr){
        cout << list_node->val;
        list_node = list_node->next;
    }
    cout << endl;
}

int main() {
    //std::cout << "Hello, World!" << std::endl;
//    ListNode list1_node2 = ListNode(3);
//    ListNode list1_node1 = ListNode(4, &list1_node2);
//    ListNode list1_node0 = ListNode(2, &list1_node1);
//
//    ListNode list2_node2 = ListNode(4);
//    ListNode list2_node1 = ListNode(6, &list2_node2);
//    ListNode list2_node0 = ListNode(5, &list2_node1);

    ListNode *listNode0 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode *listNode1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    Solution solution;
    auto result = solution.addTwoNumbers(listNode0, listNode1);
    print_list_node(result);
    return 0;
}
