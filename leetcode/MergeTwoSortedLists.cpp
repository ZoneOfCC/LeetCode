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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *current1 = l1, *current2 = l2;
        ListNode *current = nullptr;
        ListNode *result = nullptr;
        if      (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        
        while (current1 != nullptr && current2 != nullptr) {
            if (current1->val > current2->val) {
                if (result == nullptr) {
                    result = current2;
                    current = result;
                }
                else {
                    current->next = current2;
                    current = current->next;
                }
                current2 = current2->next;
            }
            else if (current1->val <= current2->val) {
                if (result == nullptr) {
                    result = current1;
                    current = result;
                }
                else {
                    current->next = current1;
                    current = current->next;
                }
                current1 = current1->next;
                
            }
        }
        while (current1 != nullptr) {
            current->next = current1;
            current1 = current1->next;
            current = current->next;
        }
        while (current2 != nullptr) {
            current->next = current2;
            current2 = current2->next;
            current = current->next;
        }
        current = nullptr;
        return result;
    }
};