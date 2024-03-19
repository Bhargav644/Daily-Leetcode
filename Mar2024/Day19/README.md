<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/task-scheduler/description/?envType=daily-question&envId=2024-03-19">Problem</a>:You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.


<b>Input:</b>tasks = ["A","A","A","B","B","B"], n = 2<br>
<b>Output:</b>8
<br>

<hr>
<b>Approach 1: Storing the frequencies in priority_queue to minimize the time and then poping them out to store in a queue which is used to block them for particular (n) time.</b>

<br/>

```
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> freq(26,0);
       for(auto i:tasks){
            freq[i-'A']++;
       }
       priority_queue<int> pq;
       for(auto i:freq){
            if(i>0) pq.push(i);
       }

       queue<pair<int,int>> q;
       int time=0;
       while(!pq.empty() or !q.empty()){
            time+=1;
            if (!pq.empty()) {
                int count = pq.top() - 1;
                pq.pop();
                if (count > 0) {
                    q.push({ count, n + time });
                }
            }

            if (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }
       }

       return time;


    }

```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(1) </li>
</ul>

<hr>
<b>Approach 2: Using Simple Mathematics</b>

<br/>

```
    int leastInterval(vector<char>& tasks, int n) {

        int freq[26] = {0};
        int maxCount = 0;


        for (char task : tasks) {
            freq[task - 'A']++;
            maxCount = max(maxCount, freq[task - 'A']);
        }

        int time = (maxCount - 1) * (n + 1);
        for (int f : freq) {
            if (f == maxCount) {
                time++;
            }
        }

        return max((int)tasks.size(), time);
    }
    
```

<br/>
<ul>
<li>Time: O(N)</li>
<li>Space: O(1) </li>
</ul>
