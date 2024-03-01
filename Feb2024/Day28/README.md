<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=daily-question&envId=2024-02-28">Problem</a>:Given the root of a binary tree, return the leftmost value in the last row of the tree.



<b>Input:</b> root = [2,1,3]<br>
<b>Output:</b> 1<br>

<hr>
<b>Approach 1:Placing each node in map according depth=>[elements] and left most will be the map[depth of tree]'s first element</b> 

<br/>

```

    int depth=INT_MIN;
    void filterDepthWise(unordered_map<int,vector<int>> &mp,int d,TreeNode* root){
        if(root==NULL) return;
        depth=max(depth,d);
        mp[d].push_back(root->val);
        filterDepthWise(mp,d+1,root->left);
        filterDepthWise(mp,d+1,root->right);
    }
    int findBottomLeftValue(TreeNode* root) {
        unordered_map<int,vector<int>> mp;
        filterDepthWise(mp,0,root);

        return mp[depth][0];
        
    }

```

<br/>
<ul>
<li>Time: O(N) </li>
<li>Space: O(N) </li>
</ul>
<hr>
<b>Approach 2:Using Level order traversal so the last one in the queue will be the left most</b> 

<br/>

```

    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int leftmost_value;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            leftmost_value = node->val;

            if (node->right) {
                q.push(node->right);
            }
            if (node->left) {
                q.push(node->left);
            }
        }

        return leftmost_value;
    }

```

<br/>
<ul>
<li>Time: O(N) </li>
<li>Space: O(m)  maximum number of nodes in one level</li>
</ul>
