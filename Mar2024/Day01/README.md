<b>[EASY]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01">Problem</a>:You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.

<b>Input:</b> s = "010"<br>
<b>Output:</b> "001"<br>

<hr>
<b>Approach 1:Placing each node in map according depth=>[elements] and calculating the checks side by side</b>

<br/>

```

    string maximumOddBinaryNumber(string s) {
        int n=s.length()-1;
        int count=0;
        for(auto i:s){
            if(i=='1') count++;
        }
        string ans="";
        while(n--){
            if(count>1){
                ans=ans+'1';
                count--;
            }
            else{
                ans=ans+'0';
            }
        }
        ans=ans+(count==1?'1':'0');
        return ans;
    }

```

<br/>
<ul>
<li>Time: O(N) </li>
<li>Space: O(1) </li>
</ul>
