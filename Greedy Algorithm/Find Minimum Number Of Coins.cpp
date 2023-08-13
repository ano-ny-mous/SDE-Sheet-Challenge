//Time Complexity: O(n)
//Space Complexity: O(1)
vector<int> MinimumCoins(int n)
{
    vector<int> coins={1000,500,100,50,20,10,5,2,1};
    vector<int> ans;
    int i=0;
    int no_of_coins=0;
    while(n)
    {
        if(n>=coins[i])
        {
            n=n-coins[i];
            ans.push_back(coins[i]);
        }
        else
        {
            i++;
        }
    }
    return ans;
}