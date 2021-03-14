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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *prev = head, *curr;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr = l1;
                l1 = l1->next;
            } else {
                curr = l2;
                l2 = l2->next;
            }
            prev->next = curr;
            prev = prev->next;
        }

        while (l1) {
            prev->next = l1;
            l1 = l1->next;
            prev = prev->next;
        }

        while (l2) {
            prev->next = l2;
            l2 = l2->next;
            prev = prev->next;
        }

        return head->next;
    }
};
