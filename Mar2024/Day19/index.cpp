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