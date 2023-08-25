// Time Complexity: O(n^m)
// Space Complexity: O(n) + O(n)
class Solution
{
public:
    int N;
    int M;

    bool vaild(bool graph[101][101], int node, vector<int> colors, int c)
    {
        for (int i = 0; i < N; i++)
        {
            if (i != node && graph[node][i] == 1 && colors[i] == c)
            {
                return false;
            }
        }
        return true;
    }

    bool rec(bool graph[101][101], int node, vector<int> colors)
    {
        if (node == N)
        {
            return true;
        }
        for (int c = 1; c <= M; c++)
        {
            if (vaild(graph, node, colors, c))
            {
                colors[node] = c;
                if (rec(graph, node + 1, colors) == true)
                {
                    return true;
                }
                colors[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n)
    {
        N = n;
        M = m;
        vector<int> colors(n, 0);
        if (rec(graph, 0, colors))
        {
            return true;
        }
        return false;
    }
};