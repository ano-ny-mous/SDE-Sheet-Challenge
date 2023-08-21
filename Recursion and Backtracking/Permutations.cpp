//Approach - 1
//Time Complexity: O(n!*n)
//Space complexity: O(n) + O(n) + O(n)
class Solution {
public:
    vector<vector<int>> ans;
    int n;
    unordered_set<int> s;
    void rec(vector<int> temp,vector<int>& nums)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i])==s.end())
            {
                temp.push_back(nums[i]);
                s.insert(nums[i]);
                rec(temp,nums);
                temp.pop_back();
                s.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int> temp;
        rec(temp,nums);
        return ans;
    }
};

//Approach - 2
//Time Complexity: O(n!*n)
//Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void rec(vector<int>& nums,int idx)
    {
        if(idx==n)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            swap(nums[idx],nums[i]);
            rec(nums,idx+1);
            swap(nums[idx],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        rec(nums,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
