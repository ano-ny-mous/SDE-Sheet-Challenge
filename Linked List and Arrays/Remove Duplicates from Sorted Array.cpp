//Approach - 1
//Time Complexity: O(n*log(n)) + O(n)
//Space Complexity: O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        int i=0;
        for(auto &ele:s)
        {
            nums[i]=ele;
            i++;
        }
        return i;
    }
};

//Approach - 2
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=i+1;
        while(j<n)
        {
            if(nums[i]==nums[j])
            {
                j++;
            }
            else
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};