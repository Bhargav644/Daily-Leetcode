<b>[EASY]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/palindrome-linked-list/?envType=daily-question&envId=2024-03-22">Problem</a>:Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.



<b>Input:</b>list = [10,1,13,6,9,5]<br>
<b>Output:</b>false
<br>

<hr>
<b>Approach 1: First finding the middle of the lined list using slow and fast pointer then reversing the half list and then comparing both of them </b>

<br/>

```
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

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(1) </li>
</ul>
