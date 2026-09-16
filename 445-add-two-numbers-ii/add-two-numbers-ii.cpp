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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        
        // Push all elements of l1 into stack s1
        ListNode* curr = l1;
        while (curr != nullptr) {
            s1.push(curr->val);
            curr = curr->next;
        }
        
        // Push all elements of l2 into stack s2
        curr = l2;
        while (curr != nullptr) {
            s2.push(curr->val);
            curr = curr->next;
        }
        
        ListNode* head = nullptr;
        int carry = 0;
        
        // Process both stacks and any remaining carry
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int val1 = 0;
            if (!s1.empty()) {
                val1 = s1.top();
                s1.pop();
            }
            
            int val2 = 0;
            if (!s2.empty()) {
                val2 = s2.top();
                s2.pop();
            }
            
            int total = val1 + val2 + carry;
            carry = total / 10;
            int newDigit = total % 10;
            
            // Insert the new node at the front of the result list
            ListNode* newNode = new ListNode(newDigit);
            newNode->next = head;
            head = newNode;
        }
        
        return head;
    }
    
};