#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
vector<int>a{1, 3, 4, 5};
vector<int>val{6, 1, 7, 7};
int n=a.size();
int w=8;
vector<vector<int>>dp(n,vector<int>(w+1,0));
 for (int i = a[0]; i <= w; i++) {
        dp[0][i] = (i / a[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= w; cap++) {
            int notTaken = 0 + dp[ind - 1][cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (a[ind] <= cap)
                taken = val[ind] + dp[ind][cap - a[ind]]; // Maximum value by taking the current item

            dp[ind][cap] = max(notTaken, taken); // Store the maximum value in the DP table
        }
    }

    cout<< dp[n - 1][w];
return 0;
}