/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *current1 = head,  *current2 = head->next;
        while (current2 != nullptr) {
            int tmp;
            tmp = current1->val;
            current1->val = current2->val;
            current2->val = tmp;
            current1 = current2->next;
            if (current1 != nullptr) current2 = current1->next;
            else current2 = nullptr;
        }
        return head;
        
    }
};