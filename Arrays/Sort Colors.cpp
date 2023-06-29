//Brute Force
//Time Complexity: O(NlogN) (Merge Sort)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Brute force 
        sort(nums.begin(),nums.end());
    }
};

//Better
//Time Complexity: O(2*N)

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int count0=0,count1=0,count2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count0++;
            }
            else if(nums[i]==1)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
        int j=0;
        for(int i=0;i<count0;i++,j++)
        {
            nums[j]=0;
        }
        for(int i=0;i<count1;i++,j++)
        {
            nums[j]=1;
        }
        for(int i=0;i<count2;i++,j++)
        {
            nums[j]=2;
        }
    }
};


//Optimal
//Time Complexity: O(N)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};