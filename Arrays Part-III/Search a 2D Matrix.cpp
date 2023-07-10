//Approach - 1
//Time Comlexity: O(n^2)
//Space Compexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rsz=matrix.size();
        int csz=matrix[0].size();
        for(int i=0;i<rsz;i++)
        {
            for(int j=0;j<csz;j++)
            {
                if(matrix[i][j]==target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//Approach - 2
//Time Comlexity: O(n)
//Space Compexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=0;
        int rsz=matrix.size();
        int csz=matrix[0].size();
        while(true)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            if(i+1<rsz&&target>=matrix[i+1][j])
            {
                i=i+1;
            }
            else if(i-1>=0&&target<=matrix[i-1][j])
            {
                i=i-1;
            }
            else if(j+1<csz&&target>=matrix[i][j+1])
            {
                j=j+1;
            }
            else if(j-1>=0&&target<=matrix[i][j-1])
            {
                j=j-1;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};

//Approach - 3
//Time Comlexity: O(nlogn)
//Space Compexity: O(1)
class Solution {
public:
    int rsz;
    int csz;

    bool binarysearch(vector<vector<int>>& matrix,int low,int high, int target)
    {
        while(low<=high)
        {
            int mid=(low+high)/2;
            int i=mid/csz;
            int j=mid%csz;
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        rsz=matrix.size();
        csz=matrix[0].size();
        return binarysearch(matrix,0,rsz*csz-1,target);
    }
};