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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int ct = 0;
        while(curr != nullptr) {
            ct++;
            curr = curr->next;
        }
        int target = ct-n+1;
        if(target==1) return head->next;
        curr = head; ct = 1;
        while(curr != nullptr){
            if(ct == target-1) {
                curr->next = curr->next->next;
                return head;
            }
            ct++;
            curr = curr->next;
        }
        return head;
    }
};
