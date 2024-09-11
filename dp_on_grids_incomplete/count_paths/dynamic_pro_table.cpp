#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png
// allowed moment is down right from 0,0 to last n-1,m-1

int f(int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = f(i - 1, j, dp);
    int left = f(i, j - 1, dp);
    return dp[i][j] = (up + left);
}

int main()
{
    int m = 3;
    int n = 2;
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)    dp[0][0] = 1;
            
            else
            {
                int up = i > 0 ? dp[i - 1][j] : 0;
                int left = j > 0 ? dp[i][j - 1] : 0;
                dp[i][j] = (up + left);
            }
        }
    }

    cout << dp[m - 1][n - 1];

    return 0;
}
