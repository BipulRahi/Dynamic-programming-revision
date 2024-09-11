#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&a,int i,int t,vector<vector<int>>&dp){
if(dp[i][t]!=-1) return dp[i][t];
if(t==0) return dp[i][t]=1;
if(t<0) return dp[i][t]=0;
if(i==0) return dp[i][t]= (t==a[i]);
// cout<<"hi";
bool pick=t>=a[i] ? f(a,i-1,t-a[i],dp):0;
bool non=f(a,i-1,t,dp);

return dp[i][t]= pick||non;
}


int main(){
vector<int>a{16, 15, 12 ,16 ,4 ,20, 16};
int t=21;
int n=a.size();
vector<vector<int>>dp(n,vector<int>(t+1,-1));



//printing of dp array
for (int i = 0; i < t+1; i++)
{
    for (int j = 0; j < t+1; j++)
    {
        cout<<dp[i][j]<<" ";

    }
    cout<<endl;
    
}

return 0;
}