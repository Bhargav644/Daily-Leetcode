<b>[EASY]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26">Problem</a>:Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.



<b>Input:</b> p = [1,2,3], q = [1,2,3]<br>
<b>Output:</b> true<br>

<hr>
<b>Approach 1:Using Recursion we can achieve this </b> 

<br/>

```

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)    return true;
        if(!p || !q)    return false;
        return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

```

<br/>
<ul>
<li>Time: O(N) number of nodes </li>
<li>Space: O(h) recursion stack of h height </li>
</ul>
<hr>
