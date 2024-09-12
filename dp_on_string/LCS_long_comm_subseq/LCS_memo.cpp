#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int f(string &a,string &b,int i,int j,vector<vector<int>>&dp){
    if(i==0 || j==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i-1]==b[j-1]) return dp[i][j]=1+f(a,b,i-1,j-1,dp);
    return dp[i][j]=max(f(a,b,i-1,j,dp),f(a,b,i,j-1,dp));
}
int main(){
    string a="abcde";
    string b="ace";
    
    // index shifting .........
    vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,-1));
    cout<<f(a,b,a.size(),b.size(),dp);


return 0;
}