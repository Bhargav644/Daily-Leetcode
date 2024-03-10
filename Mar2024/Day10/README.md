<b>[EASY]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/intersection-of-two-arrays/?envType=daily-question&envId=2024-03-10">Problem</a>:Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.





<b>Input:</b>  nums1 = [1,2,3], nums2 = [2,4]<br>
<b>Output:</b>2<br>

<hr>
<b>Approach 1: Using Two pointer it can be easily solved</b>

<br/>

```
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());

        std::vector<int> result;
        for (const auto& num : set1) {
            if (set2.find(num) != set2.end()) {
                result.push_back(num);
            }
        }


        return result;
    }

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(N) </li>
</ul>
