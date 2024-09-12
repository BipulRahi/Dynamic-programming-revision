#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    int lengthOfLIS(vector<int>& a) {
     int maxi=1;
     int n=a.size();
     vector<int>dp(n,1);
     for(int i=0;i<a.size();i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
            dp[i]=max(dp[i],1+dp[j]);
            }

        }
        maxi=max(dp[i],maxi);

     }  
     return maxi; 
    }

int main(){
vector<int>a{0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
cout<<lengthOfLIS(a);
return 0;
}