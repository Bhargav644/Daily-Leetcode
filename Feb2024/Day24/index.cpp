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