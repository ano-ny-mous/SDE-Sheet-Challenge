//Approach - 1
//Time Complexity: O(n^3)
//Space Complexity: O(1)
//TLE
class Solution {
public:
    bool search(vector<int>& nums,int element)
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==element)
            {
                return true;
            }
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1)
        {
            return n;
        }
        int counter=1;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int element=nums[i]+1;
            counter=1;
            while(search(nums,element))
            {
                element++;
                counter++;
            }
            maxi=max(maxi,counter);
        }
        return maxi;
    }
};

//Approach - 2
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1)
        {
            return n;
        }
        sort(nums.begin(),nums.end());
        int counter=1;
        int maxi=0;
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == nums[i-1]+1){
                counter++;
            }
            else if(nums[i] != nums[i-1]){
                counter = 1;
            }
            maxi = max(maxi, counter);
        }
        return maxi;
    }
};

//Approach - 3
//Time Complexity: O(n+logn)
//Space Complexity: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1)
        {
            return n;
        }
        int counter=1;
        int maxi=0;
        set<int> s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        for(auto &ele:s)
        {
            auto pos = s.find(ele+1);
            if (pos != s.end())
            {
                counter++;
            }
            else
            {
                counter=1;
            }
            maxi = max(maxi, counter);
        }
        return maxi;
    }
};
