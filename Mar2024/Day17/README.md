<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/insert-interval/description/?envType=daily-question&envId=2024-03-17">Problem</a>:You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.


<b>Input:</b>intervals = [[1,3],[6,9]], newInterval = [2,5]<br>
<b>Output:</b>[[1,5],[6,9]]
<br>

<hr>
<b>Approach 1: Simply checking the x and y of each interval and merging them accordingly </b>

<br/>

```
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int i = 0;

        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            merged.push_back(intervals[i]);
            i++;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        }
        merged.push_back(newInterval);

        while (i < intervals.size()) {
            merged.push_back(intervals[i]);
            i++;
        }

        return merged;
    }

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(1) </li>
</ul>
