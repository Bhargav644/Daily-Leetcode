int findJudge(int n, vector<vector<int>>& trust) {
    vector<vector<int>> relation(n+1);
    vector<bool> trusted(n+1);
    for(auto i:trust){
        relation[i[1]].push_back(i[0]); //0->1 list of all that trust 0 
        trusted[i[0]]=true;
    }

    for(int i=1;i<=n;i++){
        if(!trusted[i] && relation[i].size()==n-1) return i;
    }

    return -1;
}