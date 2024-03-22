bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head,*nxt,*prev;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        prev=slow;
        slow=slow->next;
        prev->next=NULL;
        fast=head;

        //reversing the list now

        while(slow){
            nxt=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nxt;
        }

        while(prev and fast){
            if(fast->val!=prev->val){
                return false;
            }
            fast=fast->next;
            prev=prev->next;
        }
        return true;


    }