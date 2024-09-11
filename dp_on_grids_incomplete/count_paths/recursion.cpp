#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png
// allowed moment is down right from 0,0 to last n-1,m-1

int f(int i,int j){
    if(i<0 || j<0) return 0;
    if(i==0 && j==0) return 1;
    
    int up=f(i-1,j);
    int left=f(i,j-1);
    return (up+left);
}


int main(){
cout<<f(2,6);

return 0;
}


