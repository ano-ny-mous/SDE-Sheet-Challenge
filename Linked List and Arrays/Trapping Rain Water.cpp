//Approach - 1
//TLE
//Time Complexity: O(n^2)
//Space Complexity: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftmax,rightmax,idx;
        int water=0;
        for(int i=1;i<n-1;i++)
        {
            leftmax=0;
            rightmax=0;
            idx=i;
            while(idx>=0)
            {
                leftmax=max(leftmax,height[idx]);
                idx--;
            }
            idx=i;
            while(idx<n)
            {
                rightmax=max(rightmax,height[idx]);
                idx++;
            }
            int val=min(leftmax,rightmax)-height[i];
            if(val>0)
            {
                water=water+val;
            }
        }
        return water;
    }
};

//Approach - 2
//Time Complexity: O(n) + O(n) + O(n)
//Space Complexity: O(n) + O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int water=0;
        vector<int> premax(n,0);
        vector<int> postmax(n,0);
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                premax[i]=max(premax[i-1],premax[i]);
            }
            premax[i]=max(height[i],premax[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i<n-1)
            {
                postmax[i]=max(postmax[i+1],postmax[i]);
            }
            postmax[i]=max(height[i],postmax[i]);
        }
        for(int i=0;i<n;i++)
        {
            int val=min(premax[i],postmax[i])-height[i];
            if(val>0)
            {
                water+=val;
            }
        }
        return water;
    }
};