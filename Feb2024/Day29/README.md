<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/even-odd-tree/?envType=daily-question&envId=2024-02-29">Problem</a>:A binary tree is named Even-Odd if it meets the following conditions:

1. The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.<br/>
2. For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).<br/>
3. For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right). <br/>

Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.



<b>Input:</b>  root = [1,10,4,3,null,7,9,12,8,6,null,null,2]<br>
<b>Output:</b> true<br>

<hr>
<b>Approach 1:Placing each node in map according depth=>[elements] and calculating the checks side by side</b> 

<br/>

```

    bool helper(TreeNode* root,unordered_map<int,vector<int>> &mp,int level){
        if(root==NULL) return true;
        if((level%2==0 && root->val%2!=1) || (level%2==1 && root->val%2!=0)) return false;
        if(mp[level].size()>0){
            if((level%2==0 && mp[level].back()>=root->val) || (level%2==1 && mp[level].back()<=root->val)) return false;
        }
      
        mp[level].push_back(root->val);
        return helper(root->left,mp,level+1) and helper(root->right,mp,level+1);
        }

    bool isEvenOddTree(TreeNode* root) {
            unordered_map<int,vector<int>> mp;
            return helper(root,mp,0);
    }

```

<br/>
<ul>
<li>Time: O(N) </li>
<li>Space: O(N) also the stack memory </li>
</ul>
<hr>
<b>Approach 2:Using Level order traversal and checking the respected conditions side by side</b> 

<br/>

```

    bool isEvenOddTree(TreeNode* root) {
        if (!root) {
            return true;
        }

        std::queue<TreeNode*> queue;
        int level = 0;

        queue.push(root);

        while (!queue.empty()) {
            int size = queue.size();
            int prev_val = (level % 2 == 0) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                // Check if the values follow the conditions
                if ((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prev_val)) ||
                    (level % 2 == 1 && (node->val % 2 == 1 || node->val >= prev_val))) {
                    return false;
                }

                prev_val = node->val;

                // Add children to the queue
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }

            level++;
        }

        return true;
    }

```

<br/>
<ul>
<li>Time: O(N) </li>
<li>Space: O(m)  maximum number of nodes in one level</li>
</ul>
