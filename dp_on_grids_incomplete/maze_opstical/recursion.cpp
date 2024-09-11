#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int f(int i, int j, vector< vector< int> > &a) {
    if(i==0 && j==0) return 1;
    if(i<0 || j<0 || a[i][j]==-1) return 0;
    int up=f(i-1,j,a);
    int left=f(i,j-1,a);
    return up+left;
}


int main(){
    vector< vector< int> > a{{0,-1},{0,0}};
    int n=a.size();
    int m=a[0].size();
    
 cout<<f(n-1,m-1,a);   

return 0;
}