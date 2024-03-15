vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int zeroCount=0;
        for(auto i:nums){
            if(i==0){
                zeroCount++;
                continue;
            }
            product*=i;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(zeroCount-1>0){
                    nums[i]=0;
                }
                else{
                    nums[i]=product/(nums[i]==0?1:nums[i]);
                }
            }
            else if(zeroCount>0){
                nums[i]=0;
            }
            else{
                nums[i]=product/(nums[i]==0?1:nums[i]);
            }
        }
        return nums;
        
    }