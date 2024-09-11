#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// partition sum mens s1==s2 right ?
// so s1+s2=sum of array (s);
// as s1=s2  2s1=s
// s1=s/2;

// conditions s should be even to have equal sums 


int main()
{
    vector<int> a{3, 1 ,1 ,2 ,2 ,1};
  
    int sum=accumulate(a.begin(),a.end(),0);
    int n = a.size();
    if(sum%2==0) return 0;
    int t=sum/2;
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));

    if (t >= a[0])
        dp[0][a[0]] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }


    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            dp[i][j] = dp[i - 1][j] + ((j >= a[i]) ? dp[i - 1][j - a[i]] : 0);
        }
    }

cout<<dp[n-1][t];

    
 for (int i = 0; i < n; i++)
{
    for (int j = 0; j < t+1; j++)
    {
        cout<<dp[i][j]<<" ";

    }
    cout<<endl;
    
}

cout<<endl<<dp[n-1][t];

    return 0;
}