
#include <bits/stdc++.h>
using namespace std;


// find wheather it is possible to have partition in the array so tht it get seprated into two sum with min diff 
// find wheather it is possible to have partition this array into two subsets such that the absolute difference between subset sums is minimum.

// means s1-s2 =minimum 
// so , s1+s2=s(sum of arry)
//  mini=min(mini,abs(s1- (s-s1) )) but when it's possible to have s1 as subset sum  



int minSubsetSumDifference(vector<int> &a, int n)
{
    int sum = accumulate(a.begin(), a.end(), 0);

    int t = sum;
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (t >= a[0])
        dp[0][a[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            dp[i][j] = dp[i - 1][j] || ((j >= a[i]) ? dp[i - 1][j - a[i]] : 0);
        }
    }

    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            if (dp[i][j] != 0)
                mini = min(mini, abs(j - (t - j)));
        }
    }
    return mini;
}

int main()
{
    vector<int>a{8, 6, 5};
  cout<<endl<<  minSubsetSumDifference(a,a.size())<<" is the min sum diff between subset "<<endl<<endl;

    return 0;
}