class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *temp=head;
        if (!head || !head->next) return nullptr;
        int N=0;
        while(temp!=nullptr){
            N++;
            temp=temp->next;
        }
        int mid=N/2;
        temp=head;
        for(int i=0;i<mid-1;i++){
          temp = temp->next;
        }  
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }
};