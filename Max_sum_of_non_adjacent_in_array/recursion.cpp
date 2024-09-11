 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 
 int solve(vector<int>&a,int i,int amt){
    if(i>=a.size())return 0;
    if(i==a.size()-1) return a[i]+amt;
    // cout<<a[i]<<endl;
    return max(solve(a,i+1,amt),solve(a,i+2,amt+a[i]));

 }


 int solve2(vector<int>&a,int i){
    if(i==0) return a[i];
    if(i<0) return 0;
    int take=solve2(a,i-2)+a[i];
    int nottake=solve2(a,i-1);
    return max(take,nottake);
 }




 int main(){
 vector<int>a{2,3,4,5};
 cout<<solve(a,0,0);
 cout<<solve2(a,a.size()-1);
 return 0;
 }