//Approach - 1
//TLE
//Time Complexity: O(n^2)
//Space Complexity: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxcount=INT_MIN;
        int maxele;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(nums[i]==nums[j])
                {
                    count++;
                }
            }
            if(maxcount<count)
            {
                maxcount=count;
                maxele=nums[i];
            }
        }
        return maxele;
    }
};

//Approach - 2
//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxcount=INT_MIN;
        int maxele;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto ele:mp)
        {
            if(ele.second>maxcount)
            {
                maxcount=ele.second;
                maxele=ele.first;
            }
        }
        return maxele;
    }
};

//Approach - 3
//Time Complexity: O(n) + O(nlogn)
//Space Complexity: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxcount=INT_MIN;
        int maxele;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                count++;
                if(count>maxcount)
                {
                    maxele=nums[i];
                    maxcount=count;
                }
            }
            else
            {
                count=0;
            }
        }
        return maxele;
    }
};

//Approach - 4
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxele;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                maxele=nums[i];
                count++;
            }
            else if(maxele==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return maxele;
    }
};