#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&a,vector<vector<int>>&dp,int i,int k){
if(i==0) {
    if(k==0 && a[i]==0) return dp[i][k]= 2;
    if(k==0 || a[i]==k) return dp[i][k]=1;
    return dp[i][k]= 0;
}
if(dp[i][k]!=-1) return dp[i][k];

return dp[i][k]=f(a,dp,i-1,k)+((a[i]<=k) ? f(a,dp,i-1,k-a[i]) : 0 );

}
int main(){
 vector<int> a{4,1,3};
    int t = 4;
vector<vector<int>>dp(a.size(),vector<int>(t+1,-1));
cout<<f(a,dp,a.size()-1,t);
return 0;
}