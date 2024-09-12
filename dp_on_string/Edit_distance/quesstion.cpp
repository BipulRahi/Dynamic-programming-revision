#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(string a,string b) {
      
        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

        // i=0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        // j=0
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        int maxi = INT_MIN;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] =  dp[i - 1][j - 1];
                else
                    dp[i][j] = 1+min(dp[i - 1][j], min(dp[i][j - 1],dp[i-1][j-1]));
            }
        }

        return dp[n][m];
    }
    int minDistance(string a, string b) {
return f(a,b);
    }
};


int main(){
    Solution s;

cout<<s.minDistance("","");
return 0;
}