//Time Complexity: O(n) + O(n)
//Space Complexity: O(n)
class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meetings;
        for(int i=0;i<n;i++)
        {
            meetings.push_back({end[i],start[i]});
        }
        sort(meetings.begin(),meetings.end());
        int count=0;
        int prev=0;
        for(int i=0;i<n;i++)
        {
            if(meetings[i].second>prev)
            {
                count++;
                prev=meetings[i].first;
            }
        }
        return count;
    }
};