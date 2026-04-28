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
    ListNode* merge(ListNode* a, ListNode* b){ 
        if (!a) return b;
        if (!b) return a;

        ListNode* head = nullptr;
        if (a->val < b->val) {
            head = a;
            a = a->next;
        } else {
            head = b;
            b = b->next;
        }
        ListNode* curr = head;

        while (a && b) {
            if (a->val < b->val) {
                curr->next = a;
                a = a->next;
            } else {
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }
        curr->next = (a ? a : b);
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        for(int i=1; i<n; i++){
            lists[i] = merge(lists[i], lists[i-1]);
        }
        return lists[n-1];
    }
};
