//Time Complexity: O(n*log(n)) + O(n)
//Space Complexity: O(n)
class Solution
{
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,double>> priority_weight;
        double max_value=0;
        for(int i=0;i<n;i++)
        {
            double priority = ((double)arr[i].value/arr[i].weight);
            priority_weight.push_back({priority,arr[i].weight});
        }
        sort(priority_weight.begin(),priority_weight.end());
        reverse(priority_weight.begin(),priority_weight.end());
        for(int i=0;i<n&&W>0;i++)
        {
            if(priority_weight[i].second<=W)
            {
                max_value+=(priority_weight[i].first*priority_weight[i].second);
                W-=priority_weight[i].second;
            }
            else
            {
                max_value+=priority_weight[i].first*W;
                break;
            }
        }
        return max_value;
    }
        
};