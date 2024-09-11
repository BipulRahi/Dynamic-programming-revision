#include<iostream>
#include<bits/stdc++.h>
using namespace std;



//Given a set of N items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with weight limit W.
//The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
//Note: Each item can be taken any number of times.

int f(int i,int val[],int a[],int w){
    if(i==0) {
        return (w/a[i])*val[i];
    }
    int pick=val[i]+ ((w>=a[i]) ? f(i,val,a,w-a[i]) : INT_MIN );
    int notpick=f(i-1,val,a,w);
    return max(pick,notpick);
}


int main(){
int a[]={2,1};
int val[]={1,1};
int n=2;
int w=3;
cout<<f(n-1,val,a,w);
return 0;
}