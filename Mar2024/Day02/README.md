<b>[EASY]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02">Problem</a>:Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

<b>Input:</b> nums = [-4,-1,0,3,10]<br>
<b>Output:</b> [0,1,9,16,100]<br>

<hr>
<b>Approach 1:First we will find square of each element and then we can directly merge them using a single while loop</b>

<br/>

```

    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            nums[i] *= nums[i];
        }
        int i=nums.size()-1;
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            if (nums[l] > nums[r]) {
                ans[i--] = nums[l++];
            } else {
                ans[i--] = nums[r--];
            }
        }

        return ans;
    }

```

<br/>
<ul>
<li>Time: O(N) </li>
<li>Space: O(N) </li>
</ul>
