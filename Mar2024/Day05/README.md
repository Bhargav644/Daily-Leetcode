<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05">Problem</a>:Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:
<br/>
1. Pick a non-empty prefix from the string s where all the characters in the prefix are equal.<br/>
2. Pick a non-empty suffix from the string s where all the characters in this suffix are equal.<br/>
3. The prefix and the suffix should not intersect at any index.<br/>
4. The characters from the prefix and suffix must be the same.<br/>
5. Delete both the prefix and the suffix.<br/>
Return the minimum length of s after performing the above operation any number of times (possibly zero times).<br/>

<b>Input:</b> s = "ca"<br>
<b>Output:</b>2<br>

<hr>
<b>Approach 1: We will just directly apply the two pointer approach where we will move left and right both pointer when both having same character we will move left pointer only when it's equal to prev-character similarly for right and if both characters are not equal it's time to break the loop that'a the minimum length.But the tricky part is what if one element left i==j in that case we will first check if it's equal to prev character that means it can be removed so the answer will be 0 and if it's not equal then the answer is 1 and normally the answer will be j-i+1</b>

<br/>

```

   int minimumLength(string s)
    {
        int i = 0, j = s.length() - 1;
        char prevChar = 'l';
        while (i < j)
        {
            if (s[i] == s[j])
            {
                prevChar = s[i];
                i++;
                j--;
            }
            else if (s[i] == prevChar)
            {
                i++;
            }
            else if (s[j] == prevChar)
            {
                j--;
            }
            else
            {
                break;
            }
        }
        if (i == j && prevChar == s[i])
        {
            return 0;
        }
        return i == j ? 1 : j - i + 1;
    }

```

<br/>
<ul>
<li>Time: O(NlogN) </li>
<li>Space: O(1) </li>
</ul>
