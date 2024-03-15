<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/binary-subarrays-with-sum/?envType=daily-question&envId=2024-03-14">Problem</a>:Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.





<b>Input:</b> nums = [1,0,1,0,1], goal = 2<br>
<b>Output:</b>4<br>

<hr>
<b>Approach 1: Using Two pointer approach</b>

<br/>

```
    int helper(int x,vector<int>& nums){
        if(x<0) return 0;
        int l=0,curr=0,res=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            while(curr>x){
                curr-=nums[l];
                l++;
            }
            res+=(i-l+1);
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(goal,nums)-helper(goal-1,nums);
    }

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(1) </li>
</ul>
