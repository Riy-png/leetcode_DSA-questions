class Solution {
public:
    ListNode* deleteHead(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* deleteTail(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next; 
        delete nodeToDelete;          

        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};