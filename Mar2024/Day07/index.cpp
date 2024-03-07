ListNode* middleNode(ListNode* head) {
        ListNode *first=head,*slow=head;
        while(first!=NULL and first->next!=NULL){
            first=first->next->next;
            slow=slow->next;
        }
        return slow;
}