#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f(vector<int>&a,int i,int k){
    if(k==0) return 1;
    if(i==0) return a[i]==k ? 1 : 0;
    return f(a,i-1,k)+( (a[i]<=k)? f(a,i-1,k-a[i]) : 0) ;
}




int main()
{
    vector<int> a{4,1,3};
    int t = 4;

cout<<f(a,a.size()-1,t);   

    return 0;
}