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