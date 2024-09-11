#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool f(vector<int>&a,int i,int t){

if(t==0) return 1;
if(i==0) return t==a[i];

bool pick=f(a,i-1,t-a[i]);
bool non=f(a,i-1,t);

return pick||non;
}


int main(){
vector<int>a{16, 15, 12 ,16 ,4 ,20, 16};
int t=21;
cout<<f(a,a.size()-1,t);
return 0;
}