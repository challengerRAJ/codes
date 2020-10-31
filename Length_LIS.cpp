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
}

vector<int> LIS(vector<int> dp,vector<int> nums)
{
        int mx=1,index=0;
        for(int i=0;i<n;i++)
        {
            if(mx<lis[i])
            {
                mx = lis[i];
                index = i;
            }
        }
        cout<<mx<<endl;
        
        vector<int> v;
        v.push_back(arr[index]);
        mx--;
        for(int i=index;i>=0;i--)
        {
            if(lis[i]==mx && arr[i]<v[v.size()-1])
            {
                v.push_back(arr[i]);
                mx--;
            }
        }
        reverse(v.begin(),v.end());
        return v;
}
