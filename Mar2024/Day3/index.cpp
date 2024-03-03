ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast=head,*slow=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }

    if(fast==NULL){ //first element to be removed 1->null and 1->2->null both case will be handled
        return head->next;
    }

    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return head;
}