<b>[EASY]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/minimum-common-value/?envType=daily-question&envId=2024-03-09">Problem</a>:Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.



<b>Input:</b>  nums1 = [1,2,3], nums2 = [2,4]<br>
<b>Output:</b>2<br>

<hr>
<b>Approach 1: Using Two pointer it can be easily solved</b>

<br/>

```

   int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]) return nums1[i];
            else if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        return -1;
    }

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(1) </li>
</ul>
