<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-03-24">Problem</a>:Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.



<b>Input:</b>nums = [1,3,4,2,2]<br>
<b>Output:</b>2
<br>

<hr>
<b>Approach 1: Multiplying every element with -1 when the we reach an element which is already in negative state that means it's two time</b>

<br/>

```
    int findDuplicate(vector<int>& nums) {
        int duplicate=-1;
        for(int i=0;i<nums.size();i++){
            int curr=abs(nums[i]);
            if(nums[curr]<0){
                duplicate=curr;
                 break;
            }
            nums[curr]*=-1;
        }

        for(int &i:nums){
            i*=-1;
        }

        return duplicate;
    }

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(1) </li>
</ul>
