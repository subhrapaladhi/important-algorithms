#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices, int fee){
    int n = prices.size();
    vector<vector<int>> dp(2,vector<int>(n));
    dp[0][0] = -prices[0]-fee; // holding positoin
    dp[1][0] = 0; //non holding position

    for(int i=1; i<n; i++){
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]-prices[i]-fee);
        dp[1][i] = max(dp[1][i-1], dp[0][i-1]+prices[i]);
    }

    return dp[1][n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<maxProfit({1,3,2,8,4,9}, 2);
    return 0;
}