#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>a{1,2,5};
    int m=5;
    int n=a.size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int j=0;j<=m;j++){
        dp[0][j]= ((j%a[0]==0) ? 1:0);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <=m; j++)
        {
        int pick = (j >= a[i] ?  dp[i][ j - a[i]] : 0);
        int notpick = dp[ i - 1][j] ;
        dp[i][j]= pick+notpick;
        }


    }
    
    cout<<dp[n-1][m];

return 0;
}