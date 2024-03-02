vector<int> sortedSquares(vector<int>& nums) {
        int negCount=0,n=nums.size();
        for(auto i:nums){
            if(i<0) negCount++;
        }
        vector<int> negSorted,ans;

        for(int i=negCount-1;i>=0;i--){
            negSorted.push_back(nums[i]*-1);
        }
        int i=0,j=negCount;

        while(i<negCount && j<n){
            if(negSorted[i]<nums[j]){
                ans.push_back(negSorted[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]);
                j++;
            }
        }
        while(i<negCount){
            ans.push_back(negSorted[i]);
            i++;
        }
        while(j<n){
            ans.push_back(nums[j]);
            j++;
        }

        for(auto &i:ans){
            i=i*i;
        }
        return ans;

    }