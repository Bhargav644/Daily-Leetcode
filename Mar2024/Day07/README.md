<b>[EASY]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07">Problem</a>:Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

<b>Input:</b>  head = [1,2,3,4,5]<br>
<b>Output:</b>[3,4,5]<br>

<hr>
<b>Approach 1: The solution is totally based on the intuition that if we have two pointer and one moving the twice of the other than when the fast pointer will reach the end the other pointer will be always at middle</b>

<br/>

```

   ListNode* middleNode(ListNode* head) {
        ListNode *first=head,*slow=head;
        while(first!=NULL and first->next!=NULL){
            first=first->next->next;
            slow=slow->next;
        }
        return slow;
    }

```

<br/>
<ul>
<li>Time: O(N) </li>
<li>Space: O(1) </li>
</ul>
