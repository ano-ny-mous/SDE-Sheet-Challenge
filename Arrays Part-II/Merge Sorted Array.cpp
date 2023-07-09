//Approach - 1
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++)
        {
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};

//Approach - 2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=0;
        while(i>=0&&!nums2.empty()&&nums1[i]!=0)
        {
            if(nums1[i]<=nums2[j])
            {
                break;
            }
            else if(nums1[i]>nums2[j])
            {
                swap(nums1[i],nums2[j]);
                j++;
                i--;
            }
        }
        int k=0;
        while(k<n)
        {
            swap(nums1[m+k],nums2[k]);
            k++;
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
    }
};

//Approach - 3
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=0;        
        int gap=ceil((double)(m+n)/2);   
        while(gap>0)
        {
            int left=0;
            int right=left+gap;
            while(right<n+m)
            {
                if(left<m&&right>=m)
                {
                    if(nums1[left]>nums2[right-m])
                    {
                        swap(nums1[left],nums2[right-m]);
                    }
                }
                else if(left>=m)
                {
                    if(nums2[left-m]>nums2[right-m])
                    {
                        swap(nums2[left-m],nums2[right-m]);
                    }
                }
                else
                {
                    if(nums1[left]>nums1[right])
                    {
                        swap(nums1[left],nums1[right]);
                    }
                }
                left++;
                right++;
            }
            if(gap==1)
            {
                break;
            }
            gap=ceil((double)gap/2);
        }

        while(k<n)
        {
            swap(nums1[m+k],nums2[k]);
            k++;
        }
    }
};