//Approach - 1
//TLE
//Time Complexity: O(n^3) + log(unique)
//Space Complexity: O(unique)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    long long sum=nums[i]+nums[j]+nums[k];
                    if(i!=j&&j!=k&&k!=i&&sum==0)
                    {
                        vector<int> temp;
                        temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }

        for(auto &ele:s)
        {
            ans.push_back(ele);
        }
        return ans;
    }
};

//Approach - 2
//TLE
//Time Complexity: O(n^2)
//Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        unordered_map<int,int> look;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            look[nums[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum=-(nums[i]+nums[j]);
                if(look.find(sum)!=look.end()&&look[sum]!=i&&look[sum]!=j)
                {
                    vector<int> temp;
                    temp={nums[i],nums[j],sum};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                
            }
        }

        for(auto &ele:s)
        {
            ans.push_back(ele);
        }
        return ans;
    }
};

//Approach - 3
//TLE
//Time Complexity: O(n^2*log(m))
//Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            set<int> look;
            for(int j=i+1;j<n;j++)
            {
                int sum=-(nums[i]+nums[j]);
                if(look.find(sum)!=look.end())
                {
                    vector<int> temp;
                    temp={nums[i],nums[j],sum};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                look.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};

//Approach - 4
//Time Complexity: O(log(n)) + O(n^2)
//Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) 
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) 
                        j++;
                    while (j < k && nums[k] == nums[k + 1]) 
                        k--;
            }
        }
    }
    return ans;
    }
};

