#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &a, int i, int t, vector<vector<int>> &dp)
{
    if (dp[i][t] != -1)
        return dp[i][t];
    //  if(t<=0) return 0;
    if (i == 0)
        return dp[i][t] = ((t % a[i] == 0) ? t / a[i] : 1e9);

    int pick = (t >= a[i] ? (1 + f(a, i, t - a[i], dp)) : 1e9);
    int notpick = f(a, i - 1, t, dp);

    return dp[i][t] = min(pick, notpick);
}

int main()
{vector<int>coins{470,18,66,301,403,112,360};
int amount =8235;
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    int g = f(coins, coins.size() - 1, amount, dp);
    cout<< (g >= 1e9 ? -1 : g);
    return 0;
}