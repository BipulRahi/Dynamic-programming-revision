#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int LBS(vector<int>&a){
    int n=a.size();
    vector<int>dp(n,1);
    vector<int>dp1(n,1);
  
int maxi=0;
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < i; j++)
        {
           if(a[i]>a[j]) dp[i]=max(dp[i],1+dp[j]);
           

        }
        
    }
    for (int i = n-1; i >=0; i--)
    {
        
        for (int j = n-1; j >i; j--)
        {
           if(a[i]>a[j]) dp1[i]=max(dp1[i],1+dp1[j]);
           

        }


        maxi=max(maxi,dp[i]+dp1[i]-1);
        
    }
    return maxi;
}


int main(){

vector<int>a{1,2,5,3,2};
cout<<LBS(a);

return 0;
}