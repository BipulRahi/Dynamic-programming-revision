#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int f(string &a,string &b,int i,int j){
    if(i==0 || j==0) return 0;
    if(a[i-1]==b[j-1]) return 1+f(a,b,i-1,j-1);
    return max(f(a,b,i-1,j),f(a,b,i,j-1));
}
int main(){
    string a="abcde";
    string b="ace";
    
    // index shifting .........
    cout<<f(a,b,a.size(),b.size());


return 0;
}