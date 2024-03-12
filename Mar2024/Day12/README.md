<b>[Medium]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/?envType=daily-question&envId=2024-03-12">Problem</a>:Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)


<b>Input:</b>  head = [1,2,-3,3,1]<br>
<b>Output:</b>[3,1]<br>

<hr>
<b>Approach 1: Using Two pointer it can be easily solved</b>

<br/>

```
        ListNode* removeZeroSumSublists(ListNode* head) {
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            int prefix_sum = 0;
            std::unordered_map<int, ListNode*> prefix_sums;
            prefix_sums[0] = dummy;
            ListNode* current = head;

            while (current) {
                prefix_sum += current->val;
                if (prefix_sums.find(prefix_sum) != prefix_sums.end()) {
                    ListNode* to_delete = prefix_sums[prefix_sum]->next;
                    int temp_sum = prefix_sum + to_delete->val;
                    while (to_delete != current) {
                        prefix_sums.erase(temp_sum);
                        to_delete = to_delete->next;
                        temp_sum += to_delete->val;
                    }
                    prefix_sums[prefix_sum]->next = current->next;
                } else {
                    prefix_sums[prefix_sum] = current;
                }
                current = current->next;
            }

            return dummy->next;
        }

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(N) </li>
</ul>
