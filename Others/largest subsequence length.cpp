#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(string &s1, string &s2, int i, int j){
    if(i==s1.size() || j==s2.size()) return 0;

    if(dp[i][j]) return dp[i][j];

    if(s1[i] == s2[j]) return dp[i][j] = 1+solve(s1,s2,i+1,j+1);

    return dp[i][j] = max(solve(s1,s2,i,j+1) , solve(s1,s2,i+1,j));
}

int largestSubsequence(string s1, string s2){
    dp = vector<vector<int>>(s1.size(),vector<int>(s1.size()));
    return solve(s1,s2,0,0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<largestSubsequence("abcde","ace");

    return 0;
}