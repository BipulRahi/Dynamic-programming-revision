#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string printLCS(int l, vector<vector<int>> &dp, string a, string b, unordered_map<string,int>& ans, vector<pair<int, int>> &p)
{

    for (auto o : p)
    {
    int i = o.first;
    int j = o.second;
    string s(l, ' ');
    int k = l - 1;

        while (i > 0 && j > 0)
        {
            if (a[i - 1] == b[j - 1])
            {
                s[k] = a[i - 1];
                i--;
                j--;
                k--;
                // cout<<a[i-1];
            }
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }

        



        ans[s]++;
    }


    for (auto o : p)
    {
    int i = o.first;
    int j = o.second;
    string s(l, ' ');
    int k = l - 1;

        while (i > 0 && j > 0)
        {
            if (a[i - 1] == b[j - 1])
            {
                s[k] = a[i - 1];
                i--;
                j--;
                k--;
                // cout<<a[i-1];
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }

        



        ans[s]++;
    }
   
}

int main()
{
    string a = "abaaa";
    string b = "baabaca";
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

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // cout<<dp[n][m];
    // this crete dp now pass this dp to na function

    int l = dp[n][m];
    unordered_map<string,int> ans;
    vector<string> anns;
    vector<pair<int, int>> d;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] == dp[n][m])
            {
                d.push_back({i, j});
            }
        }
    }

    printLCS( l, dp, a, b, ans, d);

   for(auto i:ans ) anns.push_back(i.first);
   sort(anns.begin(),anns.end());
   for(auto i:anns ) cout<<i<<" ";

    return 0;
}