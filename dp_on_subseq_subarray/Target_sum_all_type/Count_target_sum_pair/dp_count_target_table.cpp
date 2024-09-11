#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a{0, 2, 3};
    int n = a.size();
    int t = 5;
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));

 if(a[0]==0) dp[0][0]=2;
else dp[0][0]=1;
if(a[0]!=0 && t>=a[0]) dp[0][a[0]]=1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <=t ; j++)
        {
            dp[i][j] = dp[i - 1][j] + ((j >= a[i]) ? dp[i - 1][j - a[i]] : 0);
        }
    }

    cout << dp[n - 1][t];
    return 0;
}