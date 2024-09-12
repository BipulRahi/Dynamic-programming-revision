#include<iostream>
#include<bits/stdc++.h>
using namespace std;

  int printing_LIS(vector<int>& a) {
     int maxi=1;
     int n=a.size();
     vector<int>dp(n,1);
     vector<int>temp(n,0);
     int k=0;
   
     for(int i=1;i<a.size();i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                if(dp[i]<dp[j]+1){
                    dp[i]=1+dp[j];
                    temp[i]=j;
                }
            }

        }
            if(maxi<dp[i]){
                maxi=dp[i];
                k=i;
            }

     }  
    

     vector<int>ans;
     ans.push_back(a[k]);
     while(temp[k]!=k){
        k=temp[k];
        ans.push_back(a[k]);
     }
     for(auto i:ans) cout<<i<<" ";

    }
  

int main(){
vector<int>a{5,4,11,1,16,8};
printing_LIS(a);
return 0;
}