#include <numeric>

int missingNumber(vector<int>& nums) {
        long n=nums.size();
        long sum=accumulate(nums.begin(),nums.end(),0);
        long totalSum=(n*(n+1))/2;
        return totalSum-sum;
}