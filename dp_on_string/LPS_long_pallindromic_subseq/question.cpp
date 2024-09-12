#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a="leetcode";
    string z=a;
    reverse(z.begin(),z.end());
    string b=z;
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

    // i=0
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    // j=0
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    int maxi = INT_MIN;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
     
        }
    }

    cout << dp[n][m];

   
    return 0;
}