<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/?envType=daily-question&envId=2024-03-18">Problem</a>:There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.



<b>Input:</b>points = [[10,16],[2,8],[1,6],[7,12]]<br>
<b>Output:</b>2
<br>

<hr>
<b>Approach 1: Two pointer make it very easy to solve and also keeping the minimum y-axis cordinate so that we can merge them.Here we are using simple merge Intervals Problem </b>

<br/>

```
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==1) return 1;
        sort(points.begin(),points.end());
        int i=0,j=1,count=0;
        while(i<points.size() and j<points.size()){
            auto second=points[i][1];
            while(j<points.size() and points[j][0]<=second){
                second=min(second,points[j][1]);
                j++;
            }
            count++;
            i=j;
        }
        return count;
}

```

<br/>
<ul>
<li>Time: O(NLogN)</li>
<li>Space: O(1) </li>
</ul>
