//Approach - 1
//Time Complexity: O(n^2)
//Space Complexity: O(1)
vector<int> findMissingRepeatingNumbers(vector < int > nums) {
    vector<int> arr;
    int n=nums.size();
    int missing;
    int rep;
    for(int i=1;i<=n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(nums[j]==i)
            {
                count++;
            }
        }
        if(count==2)
        {
            rep=i;
        }
        if (count == 0) {
          missing = i;
        }
    }
    arr.push_back(rep);
    arr.push_back(missing);
    return arr;
}

//Approach - 2
//Time Complexity: O(n)
//Space Complexity: O(n)
vector<int> findMissingRepeatingNumbers(vector < int > nums) {
    vector<int> arr;
    int n=nums.size();
    int missing;
    int rep;
    int freq[n+1]={0};
    for(int i=0;i<n;i++)
    {
        freq[nums[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(freq[i]==0)
        {
            missing=i;
        } else if (freq[i] == 2) {
          rep = i;
        }
    }
    arr.push_back(rep);
    arr.push_back(missing);
    return arr;
}

//Approach - 3
//Time Complexity: O(n)
//Space Complexity: O(1)
//can also use n(n+1)/2 sum of n naturaal numbers
vector<int> findMissingRepeatingNumbers(vector < int > nums) {
    vector<int> arr;
    int n=nums.size();
    long long missing;
    long long rep;
    long long diff=0;
    long long sqdiff=0;
    long long add;
    for(int i=1;i<=n;i++)
    {
        diff+=(nums[i-1]-i);
    }
    for (int i = 1; i <= n; i++) {
      sqdiff += (pow(nums[i - 1], 2) - pow(i, 2));
    }
    add = sqdiff / diff;
    rep = diff + add;
    missing = add - diff;
    arr.push_back(rep / 2);
    arr.push_back(missing / 2);
    return arr;
}

//Approach - 4
//Time Complexity: O(n)
//Space Complexity: O(1)
vector<int> findMissingRepeatingNumbers(vector < int > nums) {
    int n=nums.size();
    int xr=0;
    for(int i=1;i<=n;i++)
    {
        xr^=i;
        xr^=nums[i-1];
    }

    int bitnum = (xr & ~(xr - 1));
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]&(bitnum))
        {
            one^=nums[i];
        }
        else
        {
            zero^=nums[i];
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(i&(bitnum))
        {
            one^=i;
        }
        else
        {
            zero^=i;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == zero) 
        cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};
}