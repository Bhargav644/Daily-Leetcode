<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/cheapest-flights-within-k-stops/?envType=daily-question&envId=2024-02-23">Problem</a>:You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.
<br/>
Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.
<br/>

<b>Input:</b> n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1<br>
<b>Output:</b> [0,1,2,3,5]<br>
<b>Explanation:</b> <br>
At time 0, person 0 shares the secret with person 1.<br>
At time 5, person 1 shares the secret with person 2.<br>
At time 8, person 2 shares the secret with person 3.<br>
At time 10, person 1 shares the secret with person 5.​​​​<br>
Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.<br>

<hr>
<b>Approach 1: Using Priority queue with time on priority because earlier we inform the secret early we get to know that any person has received the secret or not </b> 

<br/>

```

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        vector<pair<int,int>> adj[n];
        vector<int> visited(n,0);
        for(auto it:meetings){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        pq.push({0,firstPerson});

        while(!pq.empty()){
            auto it=pq.top();
            int time=it.first;
            int node=it.second;
            pq.pop();

            if(visited[node]) continue;

            visited[node]=true;

            for(auto itr:adj[node]){
                if(!visited[itr.first] and itr.second>=time){
                    pq.push({itr.second,itr.first});
                }
            }

        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                ans.push_back(i);
            }
        }
        return ans;

    }

```

<br/>
<ul>
<li>Time: O(E*V) </li>
<li>Space: O(E*V) </li>
</ul>
<hr>
