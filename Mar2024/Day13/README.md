<b>[EASY]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/find-the-pivot-integer/?envType=daily-question&envId=2024-03-13">Problem</a>:Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.





<b>Input:</b> n=8<br>
<b>Output:</b>6<br>

<hr>
<b>Approach 1: Derived formula using the property that (sum of series to n - sum of series to pivot(x) + (n-(x+1))) ==  sum of series to pivot(x)</b>

<br/>

```
    int pivotInteger(int n) {
        if(n==1) return 1;
        float x=2*n - (float)sqrt((2*(n*n))+2*n);
        if(fmod(x,2.0)!=0.0) return -1;
        return (int)(n-(x/2));
    }

```

<br/>
<ul>
<li>Time: O(1)</li>
<li>Space: O(1) </li>
</ul>
