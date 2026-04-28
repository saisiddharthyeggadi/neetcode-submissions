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
    bool isValid(ListNode* head, int target){
        if (!head) return false;
        ListNode* curr = head;
        int ct = 1;
        while(curr->next && ct<target){
            curr = curr->next; ct++;
        }
        if(ct == target) return true;
        return false;
    }
    ListNode* reverse(ListNode* head, int k){
        int ct = 0;
        ListNode* curr = head;
        ListNode* pre = nullptr;
        while(curr!=nullptr && ct < k){
            ListNode* nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
            ct++;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* tail = nullptr;
        bool flag = false;
        while(isValid(curr, k)){
            ListNode* nextGroup = curr;
            for(int i=0; i<k; i++) nextGroup = nextGroup->next;
            
            ListNode* newHead = reverse(curr, k);
            if(!flag) {
                head = newHead;
                flag = true;
            }
            if(tail) tail->next = newHead;
            
            curr->next = nextGroup;
            tail = curr;
            curr = nextGroup;           
        }
        return head;
    }
};