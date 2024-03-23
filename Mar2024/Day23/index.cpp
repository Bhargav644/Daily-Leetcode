ListNode* reverseList(ListNode* head){
        ListNode* cur=head,*prev=NULL,*nxt;
        while(cur){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head==NULL or head->next==NULL) return;

        ListNode* slow=head,*fast=head->next,*prev=NULL;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        prev=slow->next;
        slow->next=NULL;

        ListNode* phase1=head;
        ListNode* phase2=reverseList(prev);

        while(phase1 and phase2){
            ListNode *nxt1,*nxt2;
            nxt1=phase1->next;
            nxt2=phase2->next;
            phase1->next=phase2;
            phase2->next=nxt1;
            phase1=nxt1;
            phase2=nxt2;
        }
    }