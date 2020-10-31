https://leetcode.com/problems/longest-increasing-subsequence/submissions/
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
https://www.interviewbit.com/problems/longest-increasing-subsequence/

int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    
