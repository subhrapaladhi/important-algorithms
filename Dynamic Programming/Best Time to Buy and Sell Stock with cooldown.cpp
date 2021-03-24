#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices){
    int n = prices.size();
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = -prices[0];
    dp[1][0] = 0;

    for(int i=1; i<n; i++){
        dp[0][i] = max(dp[0][i], (i>1 ? dp[1][i-1] : 0)-prices[i]);
        dp[1][i] = max(dp[1][i], dp[0][i]+prices[i]);
    }

    return dp[1][n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<maxProfit({1,2,3,0,2});

    return 0;
}