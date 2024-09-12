#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
vector<int>a{1,7,8,4,5,6,-1,9};
vector<int>temp;
temp.push_back(a[0]);
int n=a.size();
for (int i = 1; i < n; i++)
{
    if(temp.back()<a[i]){
temp.push_back(a[i]);
        
    }
    else{
        int in=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();
        cout<<in<<" ";

        temp[in]=a[i];
    }
}
cout<<endl;
for(auto i:temp) cout<<i<<" ";
cout<<endl<<temp.size();
return 0;
}