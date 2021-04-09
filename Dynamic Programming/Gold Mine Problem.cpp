// https://www.geeksforgeeks.org/gold-mine-problem/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(vector<vector<int>> &mines, int row, int col, int &m, int &n){
  
  if(row>=m || col>=n) return 0;
  
  if(dp[row][col] != -1) {
    cout<<row<<","<<col<<endl;  
    return dp[row][col];}
  
  if(col==n-1) return dp[row][col] = mines[row][col];

  if(row==0){
    return dp[row][col] = mines[row][col] + max(
                                  solve(mines, row, col + 1, m, n), 
                                  solve(mines, row+1, col + 1, m, n)
                                );  
  }

  if(row==m-1){
    return dp[row][col] = mines[row][col] + max(
                                  solve(mines, row, col + 1, m, n), 
                                  solve(mines, row-1, col + 1, m, n)
                                );  
  }

  return dp[row][col] = mines[row][col] + max(
                                  solve(mines, row, col + 1, m, n), 
                                  max(
                                    solve(mines, row-1, col + 1, m, n), 
                                    solve(mines, row+1, col + 1, m, n)
                                ));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> mines = { {1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};

  int m = mines.size(), n = mines[0].size(), maxProfit=INT_MIN;
  dp = vector<vector<int>>(m, vector<int>(n, -1));
  for (int i = 0; i < m; i++){
    maxProfit = max(maxProfit, solve(mines, i, 0, m, n));
  }

  cout<<maxProfit;
  return 0;
}