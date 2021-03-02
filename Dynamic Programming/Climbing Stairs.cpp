// https://leetcode.com/problems/climbing-stairs/
#include<bits/stdc++.h>
using namespace std;

int countWays(int n){
    vector<int> a(n+1);
    a[0]=1, a[1]=1;
    
    for(int i=2; i<=n; i++){
        a[i] = a[i-1] + a[i-2];
    }

    return a[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n=10;
    cout<<countWays(n);
    
    return 0;
}