#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// this case is sutable when u have 1<=a[i]<=some_int but when condtion changes and 0<=a[i]<=some_int include then take care of 0 as we can add multiple things with 0 and ans will be same but we have to count them tooo as they also contributing in the count case

// so omit the sum case 


int f(vector<vector<int>>&dp,vector<int>&a,int i,int t){


if(i==0) {
    if(t==0 && a[i]==0) return dp[i][t]= 2;
    if(t==0 || a[i]==t) return dp[i][t]=1;
    return dp[i][t]= 0;
}
// cout<<t<<endl;
if(dp[i][t]!=-1) return dp[i][t];
return dp[i][t]=f(dp,a,i-1,t)+((t>=a[i]) ? f(dp,a,i-1,t-a[i]):0);
}


int main(){
vector<int>a{0,3,1};
int t=4;
vector<vector<int>>dp(a.size(),vector<int>(t+1,-1));
cout<<f(dp,a,a.size()-1,t);
return 0;
}