//Time Complexity: O(2^n)
//Space Complexity: O(2^n*log(2^n)
class Solution
{
public:
    int n;
    vector<int> ans;
    
    void rec(vector<int> arr, int i, int sum)
    {
        if(i==n)
        {
            ans.push_back(sum);
            return;
        }
        rec(arr,i+1,sum);
        rec(arr,i+1,sum+arr[i]);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        n=N;
        rec(arr,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};