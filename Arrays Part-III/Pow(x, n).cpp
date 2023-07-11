//Approach - 1
class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
    }
};

//Approach - 2
//TLE
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
        {
            return 1;
        }
        else if(n<0)
        {
            x=1/x;
            n=abs(n);
        }

        double val=x;

        for(int i=0;i<n-1;i++)
        {
            val=val*x;
        }
        return val;
    }
};

//Approach - 3
//Time Complexity: O(log2(n))
//Space Complexity: O(1)
class Solution {
public:
    double myPow(double x, int n) {
        long nn=n;
        if(nn==0)
        {
            return 1;
        }
        else if(nn<0)
        {
            x=1/x;
            nn=abs(nn);
        }

        double val=1;
        while(nn>0)
        {
            if(nn%2==1)
            {
                val=val*x;
                nn=nn-1;
            }
            else
            {
                x=x*x;
                nn=nn/2;
            }
        }
        return val;
    }
};
