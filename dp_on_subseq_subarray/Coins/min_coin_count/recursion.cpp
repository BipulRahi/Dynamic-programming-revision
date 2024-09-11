#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&a,int i,int t){

   
    if(i==0) return( (t%a[i]==0) ? t/a[i] : 1e9);

    int pick=(t>=a[i] ? (1+f(a,i,t-a[i])) : 1e9);
    int notpick=f(a,i-1,t);

    return min(pick,notpick);
}

int main(){
vector<int>a{470,18,66,301,403,112,360};
int t=8235;
cout<<( f(a,a.size()-1,t) >=1e9 ? 0:f(a,a.size()-1,t));
return 0;
}