//Approach - 1
//Time Complexity: O(n^2)
//Space Complexity: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> arr;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(arr.empty()||arr[0]!=nums[i])
            {
                int count=0;
                for(int j=0;j<n;j++)
                {
                    if(nums[i]==nums[j])
                    {
                        count++;
                    }
                }
                if(count>n/3)
                {
                    arr.push_back(nums[i]);
                }
            }
            if(arr.size()==2)
            {
                return arr;
            }
        }
        return arr;
    }
};

//Approach - 2
//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> arr;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto ele:mp)
        {
            if(ele.second>n/3)
            {
                arr.push_back(ele.first);
            }
        }
        return arr;
    }
};

//Approach - 3
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=-1,ele2=-1;
        int n=nums.size();
        int count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            if(count1==0&&nums[i]!=ele2)
            {
                ele1=nums[i];
                count1++;
            }
            else if(count2==0&&nums[i]!=ele1)
            {
                ele2=nums[i];
                count2++;
            }
            else if(ele1==nums[i])
            {
                count1++;
            }
            else if(ele2==nums[i])
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        int verifycount1=0,verifycount2=0;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(ele1==nums[i])
            {
                verifycount1++;
            }
            else if(ele2==nums[i])
            {
                verifycount2++;
            }
        }
        if(verifycount1>n/3)
        {
            ans.push_back(ele1);
        }
        if(verifycount2>n/3)
        {
            ans.push_back(ele2);
        }
        return ans;
    }
};