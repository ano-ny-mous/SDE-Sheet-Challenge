//Brute Force
//Time Complexity: O(n^2)
//Space Complexity: O(n^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int temp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp[j][n-1-i]=matrix[i][j];
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=temp[i][j];
            }
        }
    }
};

//Optimal
//Time Complexity: O(n^2)
//Space Complexity: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(auto &eachrow:matrix)
        {
            reverse(eachrow.begin(),eachrow.end());
        }
    }
};