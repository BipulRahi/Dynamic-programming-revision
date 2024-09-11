#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
vector<int>a{16, 15, 12 ,16 ,4 ,20, 16};
int t=15;
int n=a.size();
vector<vector<int>>dp(n,vector<int>(t+1,0));

for (int i = 0; i < n; i++)
{
   dp[i][0]=1;
}


    if(t>=a[0])dp[0][a[0]]=1;


for (int i = 1; i < n; i++)
{
    for (int j = 1; j <=t; j++)
    {
        dp[i][j]= dp[i-1][j]||((j>=a[i]) ? dp[i-1][j-a[i]]:0);
    }
    
}
cout<<dp[n-1][t];

return 0;
}