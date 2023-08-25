// Time Complexity: O(4^(m*n))
// Space Complexity: O(m+n)
class Solution
{
public:
    int row;
    int col;
    vector<string> ans;

    bool valid(vector<vector<int>> &mat, int i, int j)
    {
        if (i < 0 || i >= row || j < 0 || j >= col || mat[i][j] == 1)
        {
            return false;
        }
        return true;
    }

    void rec(int i, int j, vector<vector<int>> &obstacleGrid, string &temp, vector<vector<int>> &mat)
    {
        if (i < 0 || i >= row || j < 0 || j >= col)
        {
            return;
        }
        if (obstacleGrid[i][j] == 0)
        {
            return;
        }
        if (i == row - 1 && j == col - 1)
        {
            ans.push_back(temp);
            return;
        }
        if (valid(mat, i + 1, j))
        {
            temp.push_back('D');
            mat[i + 1][j] = 1;
            rec(i + 1, j, obstacleGrid, temp, mat);
            mat[i + 1][j] = 0;
            temp.pop_back();
        }

        if (valid(mat, i, j - 1))
        {
            temp.push_back('L');
            mat[i][j - 1] = 1;
            rec(i, j - 1, obstacleGrid, temp, mat);
            mat[i][j - 1] = 0;
            temp.pop_back();
        }

        if (valid(mat, i, j + 1))
        {
            temp.push_back('R');
            mat[i][j + 1] = 1;
            rec(i, j + 1, obstacleGrid, temp, mat);
            mat[i][j + 1] = 0;
            temp.pop_back();
        }

        if (valid(mat, i - 1, j))
        {
            temp.push_back('U');
            mat[i - 1][j] = 1;
            rec(i - 1, j, obstacleGrid, temp, mat);
            mat[i - 1][j] = 0;
            temp.pop_back();
        }
    }

    vector<string> findPath(vector<vector<int>> &obstacleGrid, int n)
    {
        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        string temp;
        vector<vector<int>> mat;
        mat.resize(row, vector<int>(col, 0));
        mat[0][0] = 1;
        rec(0, 0, obstacleGrid, temp, mat);
        return ans;
    }
};