<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/cheapest-flights-within-k-stops/?envType=daily-question&envId=2024-02-23">Problem</a>:There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
<br/>
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
<br/>

<b>Input:</b> n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1<br>
<b>Output:</b> 700<br>

<hr>
<b>Approach 1: Using variation of Dijkastra Algorithm  </b> 

<br/>

```

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adj[n];
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;

        queue<vector<int>> q;
        q.push({0,src,0}); //{stops,src,cost}


        while(!q.empty()){
            auto itr=q.front();
            int stops=itr[0];
            int source=itr[1];
            int cost=itr[2];

            q.pop();

            if(stops>k) continue;

            for(auto it:adj[source]){
                if(dist[it[0]]>it[1]+cost and stops<=k){
                    dist[it[0]]=it[1]+cost;
                    q.push({stops+1,it[0],it[1]+cost});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];

    }

```

<br/>
<ul>
<li>Time: O(E) E=size of flights array</li>
<li>Space: O(E) </li>
</ul>
<hr>
