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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        while (ptrA != ptrB){
            if (ptrA != nullptr) {
                ptrA = ptrA->next;
            } else {
                ptrA = headB;
            }
            if (ptrB != nullptr) {
                ptrB = ptrB->next;
            } else {
                ptrB = headA;
            }
        }
         return ptrB;
    }
};