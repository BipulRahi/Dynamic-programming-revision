#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
vector<int>a{7,8,16,20};
sort(a.begin(),a.end());
    int maxi=1;
     int n=a.size();
     vector<int>dp(n,1);
     vector<int>temp(n,0);
     int k=0;
   
     for(int i=0;i<a.size();i++){
            temp[i]=i;
        for(int j=0;j<i;j++){
            cout<<i<<" "<<j<<endl;
            if(a[i]%a[j]==0){
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
return 0;
}