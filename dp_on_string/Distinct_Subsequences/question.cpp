#include<iostream>
#include<bits/stdc++.h>
using namespace std;



const int z=1e9;
    int numDistinct(string a, string b) {
           
            int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] =( (dp[i - 1][j] + dp[i - 1][j - 1]) % (z));
            else
                dp[i][j] =( dp[i - 1][j])%(z);
        }
    }
    return dp[n][m];
    }




int main(){
cout<<numDistinct("rabbbit","rabbit");


return 0;
}