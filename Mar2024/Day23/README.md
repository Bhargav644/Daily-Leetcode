<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23">Problem</a>:You are given the head of a singly linked-list. The list can be represented as:
<br/>
L0 → L1 → … → Ln - 1 → Ln<br/>
Reorder the list to be on the following form:
<br/>
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …<br/>
You may not modify the values in the list's nodes. Only nodes themselves may be changed.



<b>Input:</b>head = [1,2,3,4]<br>
<b>Output:</b>[1,4,2,3]
<br>

<hr>
<b>Approach 1: Reversing the second part of list and using two pointer approach we can rearrange the list easily </b>

<br/>

```
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

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(1) </li>
</ul>
