int helper(int x,vector<int>& nums){
    if(x<0) return 0;
    int l=0,curr=0,res=0;
    for(int i=0;i<nums.size();i++){
        curr+=nums[i];
        while(curr>x){
            curr-=nums[l];
            l++;
        }
        res+=(i-l+1);
    }
    return res;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return helper(goal,nums)-helper(goal-1,nums);
}