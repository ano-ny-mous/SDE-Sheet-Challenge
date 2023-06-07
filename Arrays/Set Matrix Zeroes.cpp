class Solution {
public:
    int rsz;
    int csz;
    void makezeros(int r,int c,vector<vector<int>>& matrix)
    {
        for(int i=0;i<csz;i++)
        {
            matrix[r][i]=0;
        }
        for(int i=0;i<rsz;i++)
        {
            matrix[i][c]=0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> intialzeros;
        rsz=matrix.size();
        csz=matrix[0].size();
        for(int i=0;i<rsz;i++)
        {
            for(int j=0;j<csz;j++)
            {
                if(matrix[i][j]==0)
                {
                    intialzeros.push_back({i,j});
                }
            }
        }
        int sz=intialzeros.size();
        for(int i=0;i<sz;i++)
        {
            makezeros(intialzeros[i].first,intialzeros[i].second,matrix);
        }

    }
};