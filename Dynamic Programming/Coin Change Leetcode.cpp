// https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h>
using namespace std;

vector<vector<long>> dp;

long solve(vector<int> &coins, int i, int amount){
  if(amount==0) return 0;
  if(amount<0 || i==-1) return INT_MAX;
  if(dp[amount][i]!=-1) return dp[amount][i];

  if(coins[i]<=amount)
    return dp[amount][i] = min(1+solve(coins, i, amount-coins[i]), solve(coins, i-1, amount));
  return dp[amount][i] = solve(coins, i-1, amount);
}

int coinChange(vector<int> coins, int amount){
  dp = vector<vector<long>>(amount + 1, vector<long>(coins.size(), -1));
  int sol = solve(coins, coins.size()-1, amount);
  return sol==INT_MAX ? -1 : sol;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}