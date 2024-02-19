<b>[Easy]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/power-of-two/submissions/1179894397/?envType=daily-question&envId=2024-02-19">Problem</a>:Given an integer 'n', return 'true' if it is a power of 'two'. Otherwise, return 'false'.
<br>
An integer n is a power of two, if there exists an integer x such that n == 2x.. <br>

<b>Input:</b> n = 1<br>
<b>Output:</b> true<br>
<b>Explanation:</b> 2^0 = 1<br>

<hr>
<b>Approach 1: Using simple remainder-divident method</b> 

<br/>

```

    bool isPowerOfTwo(int n){
        if(n<=0) return false;
        while(n%2==0) n/=2;
        return n==1;
    }

```

<br/>
<ul>
<li>Time: O(logn) </li>
<li>Space: O(1) </li>
</ul>
<hr>

<b>Approach 2: Using simple remainder-divident method with recursion</b> 
<br/>

```

    bool isPowerOfTwo(int n){
        if(n<=0) return false;
        return (n==1 || (n%2==0 && isPowerOfTwo(n/2)));
    }

```

<br/>
<ul>
<li>Time: O(logn) </li>
<li>Space: O(logn) 'stack' </li>
</ul>
<hr>

<b>Approach 3: Bit manipulation we can simply see every number which is power of 2 will always have one bit in it ex '010' '100' etc. so that means if we bit wise & with it's predecessor we will always get 0 it's just an observation</b> 
<br/>

```

    bool isPowerOfTwo(int n){
        if(n<=0) return false;
        return ((n&(n-1))==0);
    }

```

<br/>
<ul>
<li>Time: O(1) </li>
<li>Space: O(1) </li>
</ul>
<hr>

<b>Approach 4: Using log2 we know that log2 of any number which is power of 2 will always be 2 but we also know that log2 will return in points for other so simply if floor and ciel of log2 of the number are equal that means it's always a power of 2 otherwise both will vary</b> 
<br/>

```

    bool isPowerOfTwo(int n){
        if(n<=0) return false;
        return (ceil(log2(n))==floor(log2(n)));
    }

```

<br/>
<ul>
<li>Time: O(logn) </li>
<li>Space: O(1) </li>
</ul>
<hr>

<b>Approach 5: As discussed in approach 3 number will always have one bit in it hence we can use STL method __builtin_popcount(n)</b> 
<br/>

```
    
    bool isPowerOfTwo(int n){
        if(n<0) return false;
        int bits=__builtin_popcount(n);
        if(bits==1) return true;
        return false;
    }

```

<br/>
<ul>
<li>Time: O(n) where n is number of bits </li>
<li>Space: O(1) </li>
</ul>
<hr>