//Time Complexity: O(n*log(n)) + O(n*log(n)) + O(n) + O(n)
//Space Complexity: O(1)
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        int min_platform=1;
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	int i=0,j=0;
    	while(i<n&&j<n)
    	{
    	    if(arr[i]<=dep[j])
    	    {
    	        i++;
    	    }
    	    else
    	    {
    	        j++;
    	    }
    	    min_platform=max(min_platform,i-j);
    	}
    	return min_platform;
    }
};