#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
   string a="abcde";
    string b="ace";
    int n=a.size();
    int m=b.size();
vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));

// i=0
for (int i = 0; i <= n; i++)
{
    dp[i][0]=0;
}

//j=0
for (int j = 0; j <= m; j++)
{
    dp[0][j]=0;
}

int maxi=INT_MIN;
for (int i = 1; i < n+1; i++)
{
    for (int j = 1; j < m+1; j++)
    {
     if(a[i-1]==b[j-1])  dp[i][j]=1+dp[i-1][j-1];
     else  dp[i][j]=0 ; 
    maxi=max(maxi,dp[i][j]);
    }
}


cout<<maxi;

for (int i = 0; i < n+1; i++)
{
    for (int j = 0; j < m+1; j++)
    {
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
    
}


// see the table jaha jaha max number aaya h wo hai longest common subsarray as phale in lcs jab match nhi karta tha we use to go after that word but in suarray we hve to stop when we filed to find word that matches in sereies e have to mke length 0

// to have max length we take a maxi that is our ans

return 0;
}