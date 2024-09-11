#include<iostream>
#include<bits/stdc++.h>
using namespace std;



//Given a set of N items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with weight limit W.
//The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
//Note: Each item can be taken any number of times.

int f(int i,int val[],int a[],int W, vector<vector<int>>&dp){
    if(i==0) {
      if(a[i]!=0)  return  dp[i][W]= (W/a[i])*val[i];
    }
    if(dp[i][W]!=-1) return dp[i][W];
    int pick=val[i]+ ((W>=a[i]) ? f(i,val,a,W-a[i],dp) : INT_MIN );
    int notpick=f(i-1,val,a,W,dp);
    return dp[i][W]=max(pick,notpick);
}

int main(){
int a[]={2,1};
int val[]={1,1};
int n=2;
int w=3;
 vector<vector<int>>dp(n,vector<int>(w+1,-1));

cout<<f(n-1,val,a,w,dp);
return 0;
}