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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* current = head;
        while (current != nullptr) {
            arr.push_back(current->val);
            current = current->next;
        }
        sort(arr.begin(),arr.end());
        ListNode dummy(0);
        ListNode* tail = &dummy;

        for (int val : arr) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy.next;
    }
};