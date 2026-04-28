/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* pre = nullptr;
        ListNode* head = nullptr;
        int carry = 0;
        while(curr1 != nullptr || curr2 != nullptr){
            int sum = carry;
            if(curr1 != nullptr) sum += curr1->val;
            if(curr2 != nullptr) sum += curr2->val;
            if(sum > 9) carry = 1;
            else carry = 0;
            ListNode* ans = new ListNode(sum % 10);
            if(head == nullptr) head = ans;
            else pre->next = ans;
            pre = ans;
            if(curr1 != nullptr)curr1 = curr1->next;
            if(curr2 != nullptr)curr2 = curr2->next;
        }
        if(carry) {
            ListNode* ans = new ListNode(1);
            pre->next = ans;
        }
        return head;
    }
};
