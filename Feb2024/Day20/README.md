<b>[Easy]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/missing-number/?envType=daily-question&envId=2024-02-20">Problem</a>:Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.


<b>Input:</b> nums = [3,0,1]<br>
<b>Output:</b> 2<br>
<b>Explanation:</b> n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.<br>

<hr>
<b>Approach 1: Using map or vector</b> 

<br/>

```

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n+1,-1);
        for(int i =0;i<nums.size();i++){
            v[nums[i]] = nums[i];
        }
        for(int i =0;i<v.size();i++){
            if(v[i]==-1)return i;
        }
        return 0;
    }

```

<br/>
<ul>
<li>Time: O(n) </li>
<li>Space: O(n) </li>
</ul>
<hr>

<b>Approach 2: Using xor (as we use in duplicate algo)</b> 
<br/>

```

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i =1;i<=n;i++){
            ans = ans ^ i;
        }
        for(int i =0;i<nums.size();i++){
            ans= ans^nums[i];
        }
        return ans;
    }

```

<br/>
<ul>
<li>Time: O(n) </li>
<li>Space: O(n) </li>
</ul>
<hr>

<b>Approach 3: Using sum of n numbers minus the numbers in array will eventually gives u the remaining one</b> 
<br/>

```

    int missingNumber(vector<int>& nums) {
        long n=nums.size();
        long sum=accumulate(nums.begin(),nums.end(),0);
        long totalSum=(n*(n+1))/2;
        return totalSum-sum;
    }

```

<br/>
<ul>
<li>Time: O(n) </li>
<li>Space: O(1) </li>
</ul>
<hr>

