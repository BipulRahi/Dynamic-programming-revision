 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;



 int f(vector<int>&a,int i,vector<int>&dp){
    if(i==0) return dp[i]=a[i];
    if(i<0) return 0;
    int take=f(a,i-2,dp)+a[i];
    int nottake=f(a,i-1,dp);
    return dp[i]= max(take,nottake);
 }




 int main(){
 vector<int>a{2,3,40,95,100};
 vector<int>dp(a.size(),-1);
 cout<<f(a,a.size()-1,dp);
 return 0;
 }