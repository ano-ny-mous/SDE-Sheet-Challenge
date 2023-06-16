class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1)
        {
            return 0;
        }
        int diff=0;
        int index=0;
        for(int i=0;i<n;i++)
        {
            if(prices[i]<prices[index])
            {
                index=i;
                continue;
            }
            diff=max(diff,(prices[i]-prices[index]));
        }
        return diff;
    }
};