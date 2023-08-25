// Time Complexity: O(9^(n ^ 2))
// Space Complexity: O(1)
class Solution
{
public:
    int R;
    int C;

    bool valid(vector<vector<char>> &board, int row, int col, char ch)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == ch)
            {
                return false;
            }
            if (board[i][col] == ch)
            {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            {
                return false;
            }
        }
        return true;
    }

    bool rec(vector<vector<char>> &board)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int ch = '1'; ch <= '9'; ch++)
                    {
                        if (valid(board, i, j, ch))
                        {
                            board[i][j] = ch;
                            if (rec(board) == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        R = board.size();
        C = board[0].size();
        rec(board);
    }
};