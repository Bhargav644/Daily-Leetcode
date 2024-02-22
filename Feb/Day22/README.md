<b>[Easy]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/find-the-town-judge/?envType=daily-question&envId=2024-02-22">Problem</a>:In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:
<br/>
1. The town judge trusts nobody.<br/>
2. Everybody (except for the town judge) trusts the town judge.<br/>
3. There is exactly one person that satisfies properties 1 and 2.<br/>
<br/>

<b>Input:</b> n = 2, trust = [[1,2]]<br>
<b>Output:</b> 2<br>

<hr>
<b>Approach 1: Using two arrays</b> 

<br/>

```

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

```

<br/>
<ul>
<li>Time: O(n) </li>
<li>Space: O(2(n+1)) </li>
</ul>
<hr>

<b>Approach 2: Using single array</b> 
<br/>

```

    vector<int> trustcount(n + 1, 0); 

        // Count trust relationships
        for (const auto& relation : trust) {
            trustcount[relation[0]]--;  
            trustcount[relation[1]]++;  
        }
        for (int i = 1; i <= n; ++i) {       // Check if there is a person who is trusted by everyone else
            if (trustcount[i] == n - 1) {
                return i;
            }
        }
        return -1;    // If no such person found, return -1

```

<br/>
<ul>
<li>Time: O(n) </li>
<li>Space: O(n) 'stack' </li>
</ul>
<hr>