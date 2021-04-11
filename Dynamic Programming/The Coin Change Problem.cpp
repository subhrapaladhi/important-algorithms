// https://www.hackerrank.com/challenges/coin-change/problem?isFullScreen=false
#include<bits/stdc++.h>
using namespace std;

vector<vector<long>> dp;

long solve(vector<int> &coins, int i, int n){
    if(i<0) return n==0 ? 1 : 0;

    if(n<0) return 0;

    if(n==0 || coins[i]==1) return 1;

    if(dp[n][i] != -1) return dp[n][i];

    return dp[n][i] = solve(coins, i, n-coins[i]) + solve(coins, i-1, n);
}

long getWays(int n, vector<int> c){
    sort(c.begin(), c.end());
    dp = vector<vector<long>>(n+1, vector<long>(c.size()+1, -1));
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
    
    cout<<getWays(n, c);

    return 0;
}