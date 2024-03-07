<b>[MEDIUM]</b>
<br/>

<hr/>

<h4><a href="https://leetcode.com/problems/bag-of-tokens/?envType=daily-question&envId=2024-03-04">Problem</a>:You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] donates the value of tokeni.
<br/>
Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

* Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.<br/>
* Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.<br/>
Return the maximum possible score you can achieve after playing any number of tokens.<br/>

<b>Input:</b> tokens = [100], power = 50<br>
<b>Output:</b>0<br>

<hr>
<b>Approach 1: As question suggesting that we wanna face down a token with large number and face up a token with small number yup which suggest sorting an array going greedily using two pointer</b>

<br/>

```

   int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int start=0,end=tokens.size()-1;
        int score=0,res=0;;
        while(start<=end){

            if(power>=tokens[start]){
                power-=tokens[start];
                score++;
                start++;
                res=max(res,score);
            }
            else if(score>=1){
                power+=tokens[end];
                end--;
                score--;
            }
            else{
                break;
            }
        }
        return res;
    }

```

<br/>
<ul>
<li>Time: O(NlogN) </li>
<li>Space: O(1) </li>
</ul>
