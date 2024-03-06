<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06">Problem</a>:Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

<b>Input:</b>  head = [3,2,0,-4], pos = 1<br>
<b>Output:</b>true<br>

<hr>
<b>Approach 1: We will be using fast slow pointer approach floyd cycle finding algo which says that if one is faster and one is slower then they will definitely meet at a point</b>

<br/>

```

   bool hasCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }

```

<br/>
<ul>
<li>Time: O(N) </li>
<li>Space: O(1) </li>
</ul>
