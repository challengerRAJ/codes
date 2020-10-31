https://leetcode.com/problems/maximum-product-subarray/submissions/
https://www.interviewbit.com/problems/max-product-subarray/

int maxProduct(vector<int>& nums) {
        int pmx=nums[0],pmn = nums[0];
        int mn = nums[0], mx=nums[0];
        int n=nums.size(),ans=nums[0];
        for(int i=1;i<n;i++)
        {
            mx = max({pmx*nums[i],pmn*nums[i],nums[i]});
            mn = min({pmx*nums[i],pmn*nums[i],nums[i]});
            ans = max(ans,mx);
            pmx = mx;
            pmn = mn;
        }
        return ans;
    }
