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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* curr = head;
        ListNode* evenHead = head->next;
        ListNode* oddPrev = head;
        ListNode* evenPrev = evenHead;

        while (curr->next && curr->next->next) {
            curr = curr->next->next;
            oddPrev->next = curr;
            if (oddPrev->next)
                oddPrev = oddPrev->next;
            evenPrev->next = curr->next;
            if (evenPrev->next)
                evenPrev = evenPrev->next;
        }
        oddPrev->next = evenHead;
        return head;
    }
};