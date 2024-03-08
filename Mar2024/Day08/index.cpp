int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int,int> mp;
    int maxFreq=0,ans=0;
    for(auto i:nums){
        mp[i]++;
        maxFreq=max(maxFreq,mp[i]);
    }

    for(auto i:nums){
        if(mp[i]==maxFreq) ans++;
    }
    return ans;

}