// https://www.hackerrank.com/challenges/coin-change/problem?isFullScreen=false
#include<bits/stdc++.h>
using namespace std;

vector<vector<long>> dp;

long solve(vector<int> &coins, int i, int n){
    if(i==coins.size()) return n==0 ? 1 : 0;
    if(n==0 || coins[i]==1) return dp[n][i] = 1;
    if(dp[n][i]!=-1) return dp[n][i];

    int ele = coins[i], mul=0;
    dp[n][i] = 0;
    while(mul*ele<n){
        dp[n][i] += solve(coins, i+1, n-mul*ele);
        mul++;
    }

    return dp[n][i];
}

long getWays(int n, vector<int> c){
    return solve(c, 0, n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, temp;
    cin>>n>>m;
    
    vector<int> c(m);
    for(int i=0; i<m; i++){
        cin>>temp;
        c[i] = temp;
    }
    
    sort(c.begin(), c.end(), greater<int>());
    
    dp = vector<vector<long>>(n+1, vector<long>(m,-1));
    
    cout<<getWays(n, c);

    return 0;
}