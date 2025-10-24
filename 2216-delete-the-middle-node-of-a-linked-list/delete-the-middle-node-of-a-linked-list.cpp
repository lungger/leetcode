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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 1;
        ListNode* curr = head;
        ListNode* prev = head;
        int middle;
        while (curr->next != nullptr) {
            curr = curr->next;
            n++;
        }
        middle = n / 2;

        if (!middle) {
            return nullptr;
        }

        curr = head;
        for (int i = 0; i < middle; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        return head;
    }
};