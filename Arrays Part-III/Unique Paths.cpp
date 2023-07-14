//Approach - 1
//Time Comlexity: O(m*n)
//Space Complexity: O(m*n)
class Solution {
public:
    int row;
    int col;
    int dp[101][101]={0};

    int rec(int i,int j)
    {
        if(dp[i][j]!=0)
        {
            return dp[i][j];
        }
        if(i<0||i>=row||j<0||j>=col)
        {
            return 0;
        }
        if(i==row-1&&j==col-1)
        {
            return 1;
        }
        int moveright=rec(i,j+1);
        int movedown=rec(i+1,j);
        return dp[i][j]=moveright+movedown;
    }

    int uniquePaths(int m, int n) {
        row=m;
        col=n;
        return rec(0,0);
    }
};

//Approach - 2
//Time Comlexity: O(m-1) or O(n-1)
//Space Complexity: O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int nn=m+n-2;
        int r=m-1;
        double ans=1;
        for(int i=1;i<=r;i++)
        {
            ans=ans*(nn-r+i)/i;
        }
        return (int)ans;
    }
};