//Approach - 1
//Time Complexity: O(n^2)
//Space Complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            for(int j=i+1;j<nums.size();j++)
            {
                sum=nums[i]+nums[j];
                if(sum==target && i!=j)
                {
                    arr.push_back(i);
                    arr.push_back(j);
                    return arr;
                }
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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mp[target-nums[i]]!=0&&i!=mp[target-nums[i]])
            {
                arr.push_back(i);
                arr.push_back(mp[target-nums[i]]);
                return arr;
            }
        }
        return arr;
    }
};