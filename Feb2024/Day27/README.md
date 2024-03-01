<b>[EASY]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-27">Problem</a>:Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.



<b>Input:</b> root = [1,2,3,4,5]<br>
<b>Output:</b> 3<br>

<hr>
<b>Approach 1:Diameter can be based on three conditions and we will just find max out them first condition is 1+height(left-tree)+height(right-tree) and second could be the diameter(left-tree) and third diameter(right-tree) when we calculate these three recursively we will get our maximum diameter eventually </b> 

<br/>

```

    int diameter(TreeNode* root,int &d){
        
        if(root==NULL){
            return 0;
        }
        
        int ld=diameter(root->left,d);
        int rd=diameter(root->right,d);
        
        d=max(ld+rd,d);
        
        return max(ld,rd)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int d=0;
        diameter(root,d);
        return d;
    }

```

<br/>
<ul>
<li>Time: O(N) number of nodes </li>
<li>Space: O(h) recursion stack of h height </li>
</ul>
<hr>
