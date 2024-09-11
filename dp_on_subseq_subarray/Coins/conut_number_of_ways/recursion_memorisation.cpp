#include<iostream>
#include<bits/stdc++.h>
using namespace std;


    int f(vector<int>& a, int i, int t, vector<vector<int>>& dp) {
        if (dp[i][t] != -1)
            return dp[i][t];
       
        if (i == 0)
            return dp[i][t] = (t % a[i] == 0);

        int pick = (t >= a[i] ?  f(a, i, t - a[i], dp) : 0);
        int notpick = f(a, i - 1, t, dp);

        return dp[i][t] = (pick + notpick);
    }


int main(){
vector<int>a{1,2,5};
int t=5;
     int n=a.size();
        vector<vector<int>>dp(n,vector<int>(t+1,-1));
        int c=f(a,a.size()-1,t,dp);
cout<<c;
return 0;
}