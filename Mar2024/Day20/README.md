<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/merge-in-between-linked-lists/description/?envType=daily-question&envId=2024-03-20">Problem</a>:You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:



<b>Input:</b>list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]<br>
<b>Output:</b>[10,1,13,1000000,1000001,1000002,5]
<br>

<hr>
<b>Approach 1: Simple looping will solve the problem </b>

<br/>

```
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

```

<br/>
<ul>
<li>Time: O(N+M)</li>
<li>Space: O(1) </li>
</ul>
