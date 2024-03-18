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