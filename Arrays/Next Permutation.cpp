class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz=nums.size();
        int breakpoint=-1;
        for(int i=sz-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                breakpoint=i;
                break;
            } 
        }
        if(breakpoint==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=sz-1;i>breakpoint;i--)
        {
            if(nums[i]>nums[breakpoint])
            {
                swap(nums[i],nums[breakpoint]);
                break;
            }
        }
        reverse(nums.begin()+breakpoint+1,nums.end());    
    }
};