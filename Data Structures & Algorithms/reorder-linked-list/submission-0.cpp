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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next==nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;

        while(curr != nullptr) {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        ListNode* curr0 = head;
        curr = pre;
        ListNode* nxt0 = nullptr;
        nxt = nullptr;
        while(curr != nullptr){
            nxt0 = curr0->next;
            nxt = curr->next;
            curr0->next = curr;
            curr->next = nxt0;
            curr0 = nxt0;
            curr = nxt;
        }
        return;
    }
};

