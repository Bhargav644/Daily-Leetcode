<b>[Medium]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/bitwise-and-of-numbers-range/?envType=daily-question&envId=2024-02-21">Problem</a>:Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.


<b>Input:</b> left = 5, right = 7<br>
<b>Output:</b> 4<br>

<hr>
<b>Approach 1: Shifting bits right until both the numbers get same when both gets the same we can simply move those remaining bits to left again by total number times we moved it right </b> 

<br/>

```

    int rangeBitwiseAnd(int left, int right) {
      if(left==0) return 0;
      int count=0;
      while(left!=right){
          left>>=1;
          right>>=1;
          count++;
      }
      return left<<count;
    }

```

<br/>
<ul>
<li>Time: O(logn) </li>
<li>Space: O(1) </li>
</ul>
<hr>
