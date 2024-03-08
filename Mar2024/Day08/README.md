<b>[EASY]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/count-elements-with-maximum-frequency/?envType=daily-question&envId=2024-03-08">Problem</a>:You are given an array nums consisting of positive integers.
Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
The frequency of an element is the number of occurrences of that element in the array.

<b>Input:</b>  nums = [1,2,2,3,1,4]<br>
<b>Output:</b>4<br>

<hr>
<b>Approach 1: Storing the maximum frequency</b>

<br/>

```

   int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxFreq=0,ans=0;
        for(auto i:nums){
            mp[i]++;
            maxFreq=max(maxFreq,mp[i]);
        }

        for(auto i:nums){
            if(mp[i]==maxFreq) ans++;
        }
        return ans;

    }

```

<br/>
<ul>
<li>Time: O(2N) </li>
<li>Space: O(m) </li>
</ul>


<hr>
<b>Approach 2: Can also be done in one pass just storing the max Frequency and if a frequency greater than max Frequency has came just re-initialize your ans to 1 and will return the product of frequency which passes the maxFreq and maxFreq </b>

<br/>

```

    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxFreq=0,freq=0;
        for(auto i:nums){
            mp[i]++;
            if(mp[i]==maxFreq){
                freq++;
            }
            if(mp[i]>maxFreq){
                freq=1;
                maxFreq=mp[i];
            }
        }
        return freq*maxFreq;

    }

```

<br/>
<ul>
<li>Time: O(N) </li>
<li>Space: O(m) </li>
</ul>
