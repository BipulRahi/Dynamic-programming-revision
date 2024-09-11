#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>a{1,2,5};
    int m=11;
     int n=a.size();
    vector<vector<int>>dp(n,vector<int>(m+1,0));
    for(int j=0;j<=m;j++){
       if(j%a[0]==0) dp[0][j]=j/a[0];
       else dp[0][j]=1e9;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <=m; j++)
        {
        int pick = (j >= a[i] ? (1+ dp[i][ j - a[i]]) : 1e9);
        int notpick = dp[ i - 1][j] ;
        dp[i][j]=min( pick,notpick);
        }


    }
    int ans=dp[n-1][m];
    
    cout<<ans;
    
return 0;
}