//Approach - 1
//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int maxi=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]]==0)
            {
                count++;
            }
            else
            {
                count=1;
                i=mp[s[i]];
                mp.clear();
            }
            mp[s[i]]=i+1;
            maxi=max(count,maxi);
        }
        return maxi;
    }
};