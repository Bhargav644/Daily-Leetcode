<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/contiguous-array/?envType=daily-question&envId=2024-03-16">Problem</a>:Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



<b>Input:</b>nums = [0,1]<br>
<b>Output:</b>2
<br>

<hr>
<b>Approach 1: Counting zeros and ones and also keeping track of the index of the each difference of ones ans zeros </b>

<br/>

```
    int findMaxLength(vector<int>& nums) {
        int zero=0,one=0,res=0;
        unordered_map<int,int> diff;  //diff[count(1)-count(0)] -> minimum_idx
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++;
            else one++;

            if(diff.find(one-zero)==diff.end()) diff[one-zero]=i;

            if(zero==one) res=zero+one;
            else{
                res=max(res,i-diff[one-zero]);
            }
        }
        return res;
 
    }

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(N) </li>
</ul>
