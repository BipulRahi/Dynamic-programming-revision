// Given an array arr, partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be S1 and S2. 

// Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference between S1 and S2 is equal to d

// s1-s2=d
//  here s1>s2 we ssume a/c given condition
// s1-(s-s1)=d;
// 2s1-s=d
// d+s/2=s1;


// find number of ways to mke this s1 from the given array

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
vector<int>a{5, 2, 6, 4};
int n=a.size();
int t=accumulate(a.begin(),a.end(),0);
int d=3;
t=(t-d)/2;
vector<vector<int>>dp(n,vector<int>(t+1,0));
if(a[0]==0) dp[0][0]=2;
else dp[0][0]=1;
if(a[0]!=0 && t>=a[0]) dp[0][a[0]]=1;

for (int i = 1; i < n; i++)
{
    for (int j = 0; j < t+1; j++)
    {
        dp[i][j]= dp[i-1][j] + ((j>=a[i]) ? dp[i-1][j-a[i]] : 0);
    }
    
}

cout<<dp[n-1][t];


return 0;
}