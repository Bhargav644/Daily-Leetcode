<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/product-of-array-except-self/?envType=daily-question&envId=2024-03-15">Problem</a>:Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.





<b>Input:</b> nums = [1,2,3,4]<br>
<b>Output:</b>[24,12,8,6]
<br>

<hr>
<b>Approach 1: Counting the zeros doing accordingly</b>

<br/>

```
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int zeroCount=0;
        for(auto i:nums){
            if(i==0){
                zeroCount++;
                continue;
            }
            product*=i;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(zeroCount-1>0){
                    nums[i]=0;
                }
                else{
                    nums[i]=product/(nums[i]==0?1:nums[i]);
                }
            }
            else if(zeroCount>0){
                nums[i]=0;
            }
            else{
                nums[i]=product/(nums[i]==0?1:nums[i]);
            }
        }
        return nums;
        
    }

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(1) </li>
</ul>
