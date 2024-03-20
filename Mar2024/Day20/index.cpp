ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count=0;
        ListNode* list1Copy=list1;
        while(b--){
            list1Copy=list1Copy->next;
        }
        ListNode* ans=list1;
        while(list1!=NULL){
            if(a-1==count){
                list1->next=list2;
                count++;
            }
            else if(count>=b && list1->next==NULL){
                list1->next=list1Copy->next;
                break;
            }
            else{
                count++;
            }
            list1=list1->next;
        }


        return ans;
    }