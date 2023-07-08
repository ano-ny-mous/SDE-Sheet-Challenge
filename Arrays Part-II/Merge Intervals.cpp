class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            vector<int> temp1=res.back();
            vector<int> temp2=intervals[i];
            if(temp1[1]>=temp2[0]||temp1[0]>temp2[0])
            {
                int mini=min(temp1[0],temp2[0]);
                int maxi=max(temp1[1],temp2[1]);
                
                if(!res.empty())
                {
                    res.pop_back();
                }
                res.push_back({mini,maxi});
            }
            else
            {
                res.push_back(temp2);
            }
        }
        return res;
    }
};