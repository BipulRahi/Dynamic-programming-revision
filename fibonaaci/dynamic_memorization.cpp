#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>&dp){

    if(n<=1) return dp[n]=n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}

int main(){
    int n=5;
    vector<int>dp(n+1,-1);

cout<<solve(n,dp)<<endl;
for(auto i:dp) cout<<i<<" ";
return 0;
}