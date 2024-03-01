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