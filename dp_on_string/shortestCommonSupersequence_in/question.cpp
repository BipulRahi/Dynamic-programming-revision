#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string a="abac";
    string b="cab";
    int n=a.size();
    int m=b.size();
vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for (int i = 0; i <= n; i++)
    {
            dp[i][0]=0;
            
    }
    
    for (int i = 0; i <=m; i++)
    {
            dp[0][i]=0;

    }
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        
    }
  
    
    int i=n;
    int j=m;
    string ans;
    while (i>0 && j>0)
    {
        if(a[i-1]==b[i-1]){
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1]){
            ans.push_back(a[i-1]);i--;
        }
        else{
            ans.push_back(b[j-1]);j--;
        }
    }
    
while(i>0){ans.push_back(a[i-1]);i--;}
while(j>0){ans.push_back(b[j-1]);j--;}
cout<<ans;
return 0;
}