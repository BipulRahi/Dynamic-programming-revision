#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
vector<int>a{183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
int n=a.size();
vector<int>dp(n,0);
dp[0]=a[0];
for (int i = 1; i < n; i++)
{
    int take=a[i];
    if (i>1) take+=dp[i-2];
    else take+=0;
    int intake=dp[i-1];
    dp[i]=max(take,intake);
}

cout<<dp[n-1];

return 0;
}