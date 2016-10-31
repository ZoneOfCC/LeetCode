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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        vector<ListNode*> list;
        ListNode* current = head, *result = nullptr;
        while (current != nullptr) {
            list.push_back(current);
            current = current->next;
        }
        if (list.size() < n) return head;
        if (list.size() == n && n == 1) return nullptr;
        else if (list.size() == n) result = list[1];
        else result = list[0];
        current = result;
        for (int i = 0; i != list.size(); ++i) {
            if (i != list.size() - n) {
            current->next = list[i];
            current = current->next;
            }
        }
        current->next = nullptr;
        return result;
    }
};