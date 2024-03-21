<b>[EASY]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/reverse-linked-list/submissions/1210335616/?envType=daily-question&envId=2024-03-21">Problem</a>:Given the head of a singly linked list, reverse the list, and return the reversed list.



<b>Input:</b>list1 = [10,1,13,6,9,5]<br>
<b>Output:</b>[5,9,6,13,1,10]
<br>

<hr>
<b>Approach 1: Using three pointers </b>

<br/>

```
    ListNode* reverseList(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* nxt=NULL,*prev=NULL,*curr=head;

        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(1) </li>
</ul>
