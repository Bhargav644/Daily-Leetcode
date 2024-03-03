<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=daily-question&envId=2024-03-03">Problem</a>:Given the head of a linked list, remove the nth node from the end of the list and return its head.

<b>Input:</b> head = [1,2,3,4,5], n = 2<br>
<b>Output:</b> [1,2,3,5]<br>

<hr>
<b>Approach 1: So the approach take two pointers and we will move fast to nth position in advance now fast pointer has to travel Length-n and yes now we know that moving a pointer a simultaneously from starting will reach to nth position from end when fast pointer will reach to end.</b>

<br/>

```

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

```

<br/>
<ul>
<li>Time: O(N) </li>
<li>Space: O(1) </li>
</ul>
