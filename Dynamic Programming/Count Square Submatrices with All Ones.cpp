#include<bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>>& matrix){
    int m = matrix.size(), n = matrix[0].size(), count=0;
    vector<vector<int>> dp(m, vector<int>(n,0));

    for(int i=0; i<m; i++){
        dp[i][0] = matrix[i][0];
        count += dp[i][0];
    }

    for(int i=1; i<n; i++){
        dp[0][i] = matrix[0][i];
        count += dp[0][i];
    }

    for(int i=1; i<m; i++){
        for(int j=1; i<n; i++){
            if(matrix[i][j]==1){
                dp[i][j] = 1 + min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1]));
            }
            count += dp[i][j];
        }
    }

    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}