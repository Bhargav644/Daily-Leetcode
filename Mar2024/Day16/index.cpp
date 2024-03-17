int findMaxLength(vector<int>& nums) {
        int zero=0,one=0,res=0;
        unordered_map<int,int> diff;  //diff[count(1)-count(0)] -> minimum_idx
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++;
            else one++;

            if(diff.find(one-zero)==diff.end()) diff[one-zero]=i;

            if(zero==one) res=zero+one;
            else{
                res=max(res,i-diff[one-zero]);
            }
        }
        return res;
 
    }